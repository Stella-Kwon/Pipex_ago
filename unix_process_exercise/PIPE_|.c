#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("Pipe ERROR :");
        return(1);
    }

    int pid1 = fork();
    if(pid1 == -1)
    {
        printf("Fork 1 ERROR\n");
        return 2;
    }
    // there is file descriptors that you should consider to close.
    if (pid1 == 0) // ping
    {
        dup2(fd[1],STDOUT_FILENO);
        //need to send ping's result to the stdout, so copy fd[1](writing) to a STDOUT_FILENO
        close(fd[0]);
        close(fd[1]); // already duplicated to STDOUT_FILENO, so dont need it anymore
        char * argv[] = {"ping", "-c", "5", "google.com", NULL};
        char * env[] = {NULL};
        execve("/sbin/ping", argv, env);
        /**https://velog.io/@kyj93790/Pipex-%ED%99%98%EA%B2%BD%EB%B3%80%EC%88%98environment-variable-PATH*/
        //which, whereis command will find you the path
        printf("this print should not be printed.\n");
     //becuase of exec function always end up after its process, dont need any return.   
    }
    int pid2 = fork();
    if(pid2 == -1)
    {
        printf("Fork 2 ERROR\n");
        return 3;
    }
    if (pid2 == 0) // grep
    {
        dup2(fd[0],STDIN_FILENO);//need to read and input. so stdin
        close(fd[1]);
        close(fd[0]);
        char *argv[] = {"grep","round",NULL};
        execve("/usr/bin/grep",argv,NULL);
    }
    /****
    if you dont close file descriptor in the parents process, the process will not be terminated 
    because of with stdin will be kept open (= this grep function will kept on reading until the fd[1] is closed)
    unless there is any file descriptor opened.
    (??for linux or macOS, it allows to terminate by file descriptors status)
    ****/
    close(fd[0]);
    close(fd[1]);//always recommanded to close every FD that is not for use
//especially on these exec functions when they linked to get an stdin, after all the writing descriptors got shut,
//it will acknowledge itself that there wiil be no more writing anymore.
    waitpid(pid1,NULL,0);
    waitpid(pid2,0,0);
    
    return 0;
}