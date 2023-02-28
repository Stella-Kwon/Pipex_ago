#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int pid1 = fork();//fd[]
    if (pid1 < 0)
    {
        perror("fork err :");
        return 1;
    }
    if(pid1 == 0)
    {
        sleep(3);
        printf("finished execution of pro 1 child : %d/ pr : %d\n", getpid(), getppid());
        printf("\n");
        return 0;
        //otherwise it will get waited again and back to that process and print it agian. 
    }

    int pid2 = fork();
    if (pid2 == -1)
    {
        perror("another fork err :");
        return 2;
    }    
    if(pid2 == 0)
    {
        sleep(1);
        printf("finished execution of pro 2 child : %d / pr : %d\n", getpid(), getppid());
        return 0;
    }
    //we dont' need to put else becuase there is only one way to get back after this processes(used return so)which is the parents processes
    /*int pid1_res = wait(NULL);//pid1 it will not know which child process to wait so that is why we put return in the process.
    int pid2_res = wait(NULL);//pid2*/

/*    int pid1_res = waitpid(pid1, NULL, 0); 
    //this will allow you to know which process to be waited firstly.
    printf("waited for pid1 :  %d / group id : %d\n", getpid(), getgid());
    //Calling getpid() here confirms which parent process they belong to.
     printf("waited for pid1 :  %d\n", pid1_res);//the child process id
    int pid2_res = waitpid(pid2, NULL, 0); 
    printf("waited for pid2 :  %d / group id : %d\n", getpid(), getgid());
     printf("waited for pid1 :  %d\n", pid2_res);
*/
    int pid1_res = waitpid(-1, NULL, WNOHANG);
    //WNOHANG is a flag that will return the status of the value to where the null is.
    //-1 is just waiting for any child process as wait() function alike.
    printf("waited for pid1 :  %d / group id : %d\n", getpid(), getgid());
    //Calling getpid() here confirms which parent process they belong to.
     printf("waited for pid1 :  %d\n", pid1_res);//the child process id
    int pid2_res = waitpid(pid2, NULL, 0); 
    printf("waited for pid2 :  %d / group id : %d\n", getpid(), getgid());
     printf("waited for pid1 :  %d\n", pid2_res);
    return 0;
}