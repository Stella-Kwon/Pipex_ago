#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
#include<errno.h>
#include<string.h>

// #define read 0
// #define write 1

int main(int argc, char*argv[])
{
    int fd[3][2]; // 3 pipes with fd[2]== 0 , 1
    //which means each process has 6 file discriptor, so total is 18. u need to close whole of it.
    int i = 0;
    while (i < 3)
    {
        if (pipe(fd[i]) < 0)
        {
            while(i >= 0)
            {
                close(fd[i][0]); //need to consider the other pipes that have been opened
                close(fd[i][1]); 
                i--;
            }
            return 1; 
        }
        i++;
    }
    //this time with 3 process = 2fork()
    //and with 3 pipes that goes with one direction.
    // main -> a *** fd[0][] and a -> b *** fd[1][]  and b -> main *** fd[2][]
    /*****Bascially******/
    /*
    main process will generate x and write x to a pipe[0] in order to send x to child A process.
    Child A process will read x and +5 and write it into a pipe[1], so that Child B process can acquire the x + 5
    CHild B process will read it from pipe[1] and + 5 of it and then write it into pipe[2] to send it to the main process
    main process will read the value from pipe[2]. print the value.   
    */
    
    int pid1 = fork();
    if(pid1 == -1)
    {
        perror("PID 1 FORK() ERR :");
        return 2;
    }

    if(pid1 == 0)//child  a
    {
        int x;
        close(fd[0][1]);
        close(fd[1][0]);
        close(fd[2][0]);
        close(fd[2][1]);

        if(read(fd[0][0], &x, sizeof(int)) == -1)
        {
            perror("Error on reading in A pro : ");
            return 3;
        }
        printf("Read in A pro\n");
        close(fd[0][0]);
        x += 5;
        printf("X : %d\n",x);

        if(write(fd[1][1],&x, sizeof(x)) == -1)
        {
            perror("Error on writing in A pro :");
            return 4;
        }
        printf("Written in B pro\n");
        close(fd[1][1]);
        return 0;//once it executed, i dont want to excute anything afterward. so that it can directly go to the parents process.
    }

    // close(fd[0][0]);
    // close(fd[1][0]);
    // close(fd[1][1]);
    // close(fd[2][1]);
    // int x; 
    // srand(time(NULL));
    // x = rand() % 10 + 1;

    // if (write(fd[0][1],&x,sizeof(int)) < 0)
    // {
    //     printf("Error on wrinting in the main pro : %s\n", strerror(errno));
    //     return 6;
    // }
    // close(fd[0][1]);

    //********cannot execute parents process like this in the middle, confusing the file discriptor
    int pid2 = fork();
    if(pid2 == -1)
    {
        perror("PID 2 FORK() ERR :");
        return 2;
    }
    if(pid2 == 0) // child b 
    {
        int x;
        close(fd[0][0]);
        close(fd[0][1]);
        close(fd[1][1]);
        close(fd[2][0]);

        if(read(fd[1][0],&x,sizeof(x)) < 0)
        {
            printf("Error on writing in B pro : %s",strerror(errno));
            return 7;
        }
        printf("Read in B pro\n");
        close(fd[1][0]);
        x += 5;
        printf("X : %d\n",x);

        if(write(fd[2][1], &x, sizeof(int)) < 0)
        {
            perror("Error on writing in B pro :");
            return 8;
        }
        printf("Written in the main pro\n");
        close(fd[2][1]);
        return 0;//once it executed, i dont want to excute anything afterward. so that it can directly go to the parents process.
    }
    //parent process
    close(fd[0][0]);
    close(fd[1][0]);
    close(fd[1][1]);
    close(fd[2][1]);
    int x; 
    // srand(time(NULL));
    // x = rand() % 10 + 1;
    //printf("The First X : %d\n", x);
    printf("X :");
    scanf("%d", &x);

    if (write(fd[0][1],&x,sizeof(int)) < 0)
    {
        printf("Error on wrinting in the main pro : %s\n", strerror(errno));
        return 6;
    }
    printf("Written in A pro\n");
    close(fd[0][1]);

    if(read(fd[2][0],&x, sizeof(int)) == -1)
    {
        perror("Error on reading in the main pro :");
        return 9;
    }
    printf("Read in the main pro\n");
    close(fd[2][0]);

    printf("The last X value is %d\n", x);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}