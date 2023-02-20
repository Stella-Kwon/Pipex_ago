#include<stdio.h>
#include<unistd.h>
#include<errno.h>
//#include<sys/wait.h>
#include<sys/stat.h> //fifo
#include<sys/types.h> //fifo file types
#include<fcntl.h> 
#include<stdlib.h> //Srand(time(NULL)) or srand() or rand()
#include<time.h>//Srand(time(NULL))

int main(int argc, char *argv[])
{
    if (mkfifo("sum", 0777) == -1)
    {
        if(errno != EEXIST)
        {
            printf("There is another problem than alreadt file existency\n");
            return 1;
        } 
    }
 //1********** make the random number to be stored in array.
    int arr[5];
    srand(time(NULL));//give you different sequence of rand() value
    int i;

    for(i = 0; i < 5; i++)
    {
        arr[i] = rand() % 100 ;// randomly 0 to 99 will get picked ; 
       //난수의 범위는 0~RAND_MAX 까지
        printf("Generating arr[%d] : %d\n", i, arr[i]);
    }

    /*srand() reference to https://reakwon.tistory.com/63
    https://shaeod.tistory.com/292*/
//2************** make file description for writing and then write it down.
    int fd = open("sum", O_WRONLY);
    if (fd == -1)
    {
        printf("Opening ERROR");
        return 2;
    }
    i = 0;
    if (write(fd, &arr, sizeof(int)*5) == -1)//write whole at once =write(fd, &arr, sizeof(int)*5) =write(fd, arr, sizeof(arr))
        {
            perror("Writng Error :\n");
            return 3;
        }
     printf("Wrote\n");
    // while(i < 5)//one at a time writing array
    // {
       
    //     if (write(fd, &arr[i], sizeof(int)) == -1)
    //     {
    //         perror("Writng Error :\n");
    //         return 3;
    //     }
    //     printf("Wrote array[%d] : %d\n", i, arr[i]);
    //     i++;
    // }
    close(fd);
    printf("Closed.\n");

    int res[1];
    fd = open("sum",O_RDONLY);
    if(fd == -1)
    {
        perror("sum read only fd error:");
        return 4;
    }
    
    if(read(fd, &res[1], sizeof(int)) == -1)//also this recommended to &res[1] as it is void * position.
    {
        perror("reading error:");
        return 5;
    }
    //printf("Have result : %d\n", &res[1]);//this one gives some weird number.
    printf("Have result : %d\n", res[1]);
    close(fd);
    printf("Closed reading fd\n");
    return 0;
}