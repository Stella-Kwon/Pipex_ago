#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork() : ");
        return 1;
    }

    if (pid == 0)
    {//child process

        int file = open("pingResult.txt",O_WRONLY | O_CREAT, 0777 );
        //to add more flag use'|',and the last part we need permission in Octal value like fifo we did
       
       if (file == -1)
        {
            return 2;
        }
        printf("The fd to pingResult.txt : %d\n", file);
        int file2 = dup2(file, STDOUT_FILENO);
        printf("The duplicated fd : %d\n", file2);//this will be printed in file not printed in the terminal as the fd has been changed to 1.
        close (file);//which we are not using anymore.


        /*dup(file) = only duplicate the file itself to the other filedescritor*/
        /*for ex: there is alwasys 0 : STDIN_FILENO, 1 : STDOUT_FILENO, 2 :STDERR_FILENO opened when you start to program.
        : this 3 file descriptor result will show on the terminal
        so if there is no file have opened then the file now that we have created has 3 num file descriptor
        and if you do dup(file) then at 4 num file descriptor will connect to the copyed file. so 3,4 is the same file that has differnet file descriptor.
        but if you use dup2(file, 1(=STDOUT_FILENO)) it will delete STDOUT connect and replace it to the file "pingResult.txt".
        **when you duplicate the file descriptor that are already opened and process ID will still remain, no changes.
        so the result of the process which is execlp() printed out in that file.
        That is how you can put the result in to the file.*/ 
        
        int err = execlp("ping","ping","-c","3","google.com", NULL);
        //i dont want this result to print out in the terminal, so gonna put outcome in the file.
        //*****************
        //ONE MORE THING TO CONSIDER IS THAT EXECLP IS RUNNING DIRECTLY TO C PROGRAM, TO THE PROGRAM WHERE THEY EXIST (YOU CAN FIND WHERE THE PING EXIST BY COMMAND "WHERIS PING") WHICH IS NOW ON PING
        //WHICH MEANS THAT BY USING '|' PIPE, THIS CANNOT WORK.
        //THROUGH TERMINAL USING | IT READS THE BASH OR BATCH SCRIPT, SO CAN BE WORK.
        // BUT WIHT EXEC()WE CANNOT, BECAUSE THEY DONT GET ANY BASH SCRIPT.
        // PING ITSELF THOUGH THE EXEC THAT GOES INTO LIKE MAIN.C FILE AND RUN THE PROGRAM SO WHICH THEY TAKE
        // IN THE PARAMETER IS LIKE ARGV. 

        // SO FOR EXAMPLE TO PRINT ONLY ROUND TRIP "RTT" LINE IN THE RESULT
        // USIING EXECLP("PING","PING","-C","3","GOOGLE.COM","|","GREP","\"RTT"\",NULL)WOULD NOT WORK.        
        // BUT YOU CAN DO SIMILAR BEHAVIOUR WITH PIPE WITH MORE ELABORATE THAN JUST GIVING OUT MORE PARAMETER.
        //********************
        
        if(err == -1)
        {
            printf("Could not find program to execute!\n");
            return 3;
        }
        printf("This should not launch on the terminal\n");
        
    }
    else
    {
        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus))
        {
            int statuscode = WEXITSTATUS(wstatus);
            if(statuscode == 0)
                printf("Successful\n");//there is no like external signal that intervine to terminate normally.
            else
                printf("Failure with status code %d\n", statuscode);
        }
        printf("Some post processing goes here!\n");
    }
    return(0);
}
