#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        return 1;
    }

    int pid = fork();
    if (pid == -1)
    {
        return 2;
    }

    if (pid == 0)
    {
        close(fd[0]);
        srand(time(NULL));
        int x[10];
        int i;
        int z = rand() % 10 + 1;//cannot be more than array amount
        printf("Generating :");
        for(i = 0; i < z; i++)
        {
            x[i] = rand() % 10 + 1;
            //printf("x[%d] : %d\n", i, x[i]);
            printf("%d ", x[i]);
            fflush(stdout);
        }
        printf("\n");
        if(write(fd[1],&z,sizeof(int))<0)//z needed to be sent to parents 
            return 3;
        printf("Sent z : %d\n", z);
        if(write(fd[1],&x,sizeof(x/*[=sizeof(int) * z]*/))==-1)
            {
                return(3);
            }
        printf("Wrote array\n");
        //  for(i = 0; i < z; i++)
        // {
        //     printf("Wrote %d\n",x[i]);
        // }
        close(fd[1]);
    }
    else{
        close(fd[1]);
        int y[10];
        int i, z, sum = 0;
        printf("Recieving..\n");
        if(read(fd[0], &z, sizeof(int))<0)
        {return 4;}
        printf("Got z : %d\n", z);
        if(read(fd[0], &y, sizeof(y/*[=sizeof(int) * z]*/))==-1)
            {
                return(4);
            }
        printf("Recieved array\n");
        close(fd[0]);
        for(i = 0; i < z; i++)
        {
            //printf("Read %d\n",y[i]);
            sum += y[i];
        }
        printf("TOTAL sum : %d\n", sum);
        wait(NULL);
    }
    return 0;
}