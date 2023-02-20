#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
    int fd1[2];// C -> P
    int fd2[2];// P -> C
//REASON THAT THERE SHOULD BE  2 PIPES;
    //because the process will start at the same time, parallelly
    //they will not know procedures which to read first or write to read next
    //Usually it might be lost to read as the other process read first that it should not have read,
    //so if there is another command executing between the read and write to give some time(ex, printf for checking steps)
    // ----- to each process to read or write, it might work fine but might not. 
    //That is why we should use pipe only one way, not both-way flow.

    if (pipe(fd1) == -1)
    {
        return 1;
    } 
    if (pipe(fd2) == -1)
    {
        return 1;
    } 

    pid_t pid = fork();
    if (pid == -1){return 2;}

    if(pid == 0)//in child process
    {
        close(fd1[0]);//close description first that you r not gonna use
        close(fd2[1]);
        int y;
        for(int i = 0; i < 5; i++)
        {
            printf("CH 1 : %d\n", i);
            if(read(fd2[0], &y, sizeof(int)) == -1)
            {
                return 2;
            }
            printf("CH 2 :Read Y : %d\n", y);
            y *= 4; 
            if(write(fd1[1], &y, sizeof(int)) == -1)
            {
                return 3;
            }
            printf("CH 3 : Wrote Y *4 : %d\n", y);
        }

        close(fd2[0]);
        close(fd1[1]);
        printf("CH 4 : closed child\n");
    }
    else// parent process = execting staff to the terminal. main
    {
        close(fd1[1]);
        close(fd2[0]);
        int x;
        srand(time(NULL));
        
        for(int i = 0; i < 5; i++)// this condition should have at the both pipes to work 5 times. 
        {
            printf("P 1 : %d\n", i);
            x = rand() % 10;
            if (write(fd2[1], &x, sizeof(int))==-1)
            {
                return 4;
            }
            printf("P 2 : Wrote x: %d\n", x);//this kind of command will give child process to retrieve the data
            //you can just overwrite on x as you alread sent it to child process
            if (read(fd1[0], &x, sizeof(int)) == -1)
            {
                return 5;
            }
            printf("P 3 : Read Result : %d\n", x);
        }
        
        close(fd1[0]);
        close(fd2[1]);
        printf("P 4 : Closed");
        wait(NULL);
    }
    return(0);
}
