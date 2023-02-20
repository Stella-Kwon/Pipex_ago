#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

//#include <>
int main (int argc, char *argv[])
{
    if(mkfifo("myfifo1", 0777)== -1) //mkfifo can be used in the terminal => mkfifo myfifo1 
    {
        if( errno != EEXIST)
        {
            printf("Could not create fifo file : %s\n", strerror(errno));
            return 1;
        }
    }
   /*some unique functions have a status value returned that is 0 = success,
    -1 =failed, and also with some other values that have meaning for something.
    HERE that with mkfifo == -1 also if there is a file called that same,
    then it will fail to create and return -1 value. 
    To try to avoid that we give another condition with errno != EEXIST 
    so that we can see the failure is caused by some other problem besides the already existing file.*/

    // 0777 in Octal that the file is going to be able to be read from or wrote to by anybody in the system. 
    //pipe ()only can creat a data stream between processes that is under the same hierachy.
    /*pipe itself can be set witg 2 filedescriptors that is independent meanwhile using fork to create a copy.*/
    /*FIFO features that is existed in unix system that you can 
    use as what pipe() does : share data
    use as file : file type that you can write and read from any process that you open.*/

    //to make fifo is mkfifo("namefofile",permision mode), this fifo file will be used as a pipe.
    
    printf("Opening...\n");
    /*might not have any outcome and the it is just hanging there,
    so to check which procedure has been stopped, you can print it out. */
    /*when it comes to this instance that it hangs in the execution of open(), fifo its special feature is that it should open both ends, writing, and reading.
    which means that you should open another terminal and cat fifo file so it opens the read section.*/
    /*if we opened read fd {open("myfifo1",O_RDONLY)} and doing cat would not work, it will hang there as it didnt opened write fd.
    so you should do cat > myfifo1 and type text in there to open write fd.*/
    /*but if you open("myfifo1",O_RDWR); then it will work without opening another terminal to open the fd*/
    int fd = open("myfifo1",O_WRONLY);
    //need to open file and give descriptor. In pipe you will get filedescriptor write away but fifo you need to seperately.
    if (fd == -1)
    {   
        perror("There is an error in opening: \n");
        return 3;
    }
    printf("Opened.\n");
    int x ;
    x = 97;//askii = a =97
    if (write(fd, &x, sizeof(int)) == -1)
    {
        printf("Error in writing : %s\n", strerror(errno));
        return 2;
    }
    // if (read(fd, &x, sizeof(int)) == -1)
    // {
    //     printf("Error in reading: %s\n", strerror(errno));
    //     return 2;
    // }
    printf("Written.\n");
    // printf("Reading.\n");
    close(fd);
    printf("Closed.\n");
    return 0;
}