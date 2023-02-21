#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd[2];
    if(pipe(fd) < 0)
    {
        perror("Pipe ERROR : ");
        return 1;
    }

    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork ERROR : ");
        return(2); // = exit (2);
    }

    if(pid == 0)
    {
        close(fd[0]);
        /*file descriptor reference : https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/*/
        char str[200];//total number starts from 1 to how many elements + 1 for the null;
        printf("Please type a string :");
        fgets(str,sizeof(str)/*200*/,stdin);//in str, how much size of str place, where it will get from ; stdin(terminal), or file.....
        //https://www.digitalocean.com/community/tutorials/fgets-and-gets-in-c-programming
        //printf("\n");//after fgets it give \n
        //printf("%lu\n", sizeof(str));== 200
        printf("%lu\n", strlen(str));
        /*HELLO = strlen(str) value = 6, because it counts the \n at the end*/
        str[strlen(str) - 1] = '\0'; //200 includes NULL space. and it is index that is why need to be -1 than the strlen value
        /*so after putting at the end \0 rather than \n. now it counts 5 as normal. */
         printf("%lu\n", strlen(str));
        int z = strlen(str) + 1/*NULL*/;
        if (write(fd[1], &z, sizeof(int)) == -1)
        {
            perror("Writing z ERROR :");//no need \n
            return 3;
        }
        if (write(fd[1],&str,z) < 0) // buffer to write data to, but where the date is. to write in fd
        {
            perror("Writing string Error :");
            return 4;
        }
        printf("Wrote string and z\n");
        close(fd[1]);
    }   
    else{
        close(fd[1]);
        char str[200];
        int z;
        /*****this has 4 bytes more but easy procedure */
        if (read(fd[0],&z, sizeof(int))< 0)
        {
            perror("Reading z ERROR :");
            return 5;
        }
        if (read(fd[0],&str, z)== -1)
        {
            perror("Reading string ERROR :");
            return 6;
        }

        /****more procedure but less memory use*/ ////BUT NOT WORKING>>>>need to find how 
        // int i = 0;
        // sleep(10);//because the fgets child process doesnt execute before this while loop, so it it just not get in to the loop 
        // while(i<200&&str[i] != '\0')
        // {
        //     if(read(fd[0],&str[i],sizeof(char)) == -1)
        //     {
        //         perror("READING ERROR :");
        //         return 6;
        //     }
        //     i++;
        //     printf("string[%i] : %d\n",i ,str[i]);
        // }
        // str[i] = '\0';
        printf("String has been written.\n");
        printf("string : %s\n",str);//array, so dont need &str.
        close(fd[0]);
        wait(NULL);
    }
    return 0;
}