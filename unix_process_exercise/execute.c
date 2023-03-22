//all exec()family functions, once their command executed unless there is an error,
//it will do nothing after any functions you have written. but with different process it works.
//http://shumin.co.kr/linux-exec-%EA%B3%84%EC%97%B4-%ED%95%A8%EC%88%98/
//https://iredays.tistory.com/126
//youtube https://www.youtube.com/watch?v=OVFEWSP7n8c
//https://www.youtube.com/watch?v=DiNmwwQWl0g&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=12

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s || fd < 0)
		return ;
	len = strlen((const char *)s);
	write(fd, s, len);
}

int error_exit(int exitnum, char * mess, char * filename)
{
    ft_putstr_fd ("zsh: ", 2);
    if(mess)
        ft_putstr_fd(mess, 2);
    if(filename)
    { 
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(filename, 2);
    }
    ft_putstr_fd("\n", 2);
    return(exitnum);
}

int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == -1)
    {
        return 11;
    }

    if (pid == 0)
    {//child process
       //int err = execlp("ping","ping","-c", "3","google.com", NULL);
       int err = execlp("ls","ls","-l", NULL);
       //execlp("mkfifo","mkfifo","testfifo",NULL);
       if (errno == 2)//number two error is when failing searching cmd
		    error_exit(EXIT_FAILURE, "command not found",NULL);
	    else
		    error_exit(EXIT_FAILURE, "failure by execlp", strerror(errno));
    //    if(err == -1)//general cases of error 
    //    {
    //     printf("Could not find program to execute!\n");
    //     return 2;
    //    }
    //    printf("This should not launch on the terminal\n");//this one will never gonna print it out in this case.
        //if the if(err =-1) wasnt there ,then this printf will be printed if the execlp not worked.
    }
    else
    {
        //wait(NULL);//here how do you know that is is successed? 
        //to try to no the which status the child has we use this
        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus)) //in this type of macro
        {
            int statuscode = WEXITSTATUS(wstatus);
            //statuscode mean like return or exit value. signal ..?
            if(statuscode == 0)//always program executed perfectly =0
                printf("Successful\n");
            else
                printf( "Failure with status code %d\n",statuscode);
        }
        printf("Some post processing goes here!\n");
    }
    return(0);
}
