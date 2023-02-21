#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ARRAY[5];//reading buffer
    int fd = open("sum",O_RDONLY);
    if (fd == -1)
    {
        perror("FD RD ERRPOR : \n");
        return 1;
    }

   
    //******* anyway when you call read it will read always one at a time.
    if(read(fd, &ARRAY, sizeof(ARRAY)) == -1)// (&ARRAY or ARRAY with sizeof(int) *5 or sizeof(ARRAY)))
        {
            perror("READING ERROR : \n");
            return 2;
        }
//not putting sizeof(ARRAY), there is also another way of passing the value of elements in a array.
//but to check each procedure of reading, recommend bottom one, but for the faster process upper one.
       
    int i;
    // for(i = 0; i < 5; i++)
    // {
    //     if(read(fd, &ARRAY[i], sizeof(int)) == -1)
    //     //read will do the same even you put (&ARRAY or ARRAY with sizeof(int) *5 or sizeof(ARRAY))) or &ARRAY[i]
    //     {
    //         perror("READING ERROR : \n");
    //         return 2;
    //     }
    //     printf("READING VALUE ARRAY[%i] : %d\n", i, ARRAY[i]);
    // }
    
    close(fd);
    printf("CLOSED READING FD\n");
    int sum = 0;
    for(i = 0; i < 5; i++)
    {
        sum += ARRAY[i];
    }
    printf("Result is : %d\n", sum);

    fd = open("sum",O_WRONLY);
    if(fd == -1)
    {
        perror("OPENING WRITING FD ERROR:\n");
        return 3;
    }
    if(write(fd, &sum, sizeof(int)) == -1) 
    //(write(fd, sum, sizeof(int))without & before writing sum, it still works but as it should be a parameter of const void * (buffer), so better to put & 
    {
        printf("There is a error writing to sum fifofile : %s\n", strerror(errno));
        return 4;
    }
    printf("Wrote sum : %d\n", sum);
    close(fd);
    printf("Closed fd write\n");
    return 0;
}
//with two terminal you will execute one of the files respectively. 
//you will find out that they are piped together ;  shared data.