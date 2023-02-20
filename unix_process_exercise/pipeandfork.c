#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include<sys/wait.h>

#define rd 0
#define wr 1

int main (int argc, char *argv[])
{
	int fd[2]; // two int elements array in fd
	//file descriptor is key for access to the file either read or write data to.
	//pipe is IPC that helps you to share the data between process.
	//creating a data stream which you can think as a memory file buffer. 
	//usually pipe doesn't follow in order as you have coded. 
	//so, to avoid it using 2  pipes for each way, so parent to child and child to parents.
	if(pipe(fd) == -1)
	{
		printf("there is some error in piping : %s\n", strerror(errno));
		return 1; // it is good to give some value to check in which cases that the problem occurs
	}
	// always need to remember to to pipe first and then fork!
	//because the pipe with fd parameter will create the pipe line with 2 file descriptor.
	// when you fork it? the file descript will be copied in both processes.
	// SO ALWAYS THINK AND CLOSE IT AS EVERY PROCESS HAS independent 2 FILEDESCRIPTORS.

	pid_t id = fork();
	//usually fork or write will not occur and error easily but still giving some protection
	//might user devices has some limitation to handle the some certain amount of processes.
	if (id == -1)
	{
		perror("fork error : \n");
		return 4;
	}
	if (id == 0)//child
	{
		close(fd[rd]);//WHEN YOU CLOSE OTHER WRITEING DESCRIPTOR WILL OPEN
		int x;
		printf("Enter a number : ");
		scanf("%d", &x); // GET NUM FROM USER AND PUT IT IN X;

		if(write(fd[wr], &x, sizeof(int)) == -1)//it will still write
		{
			printf("there is an error occur in writing to the pipe :\n%s\n", strerror(errno));
			return(2);
		}
		close(fd[wr]);
		printf("The data has been stored perfectly in the pipe : %d \n", x);
	}
	else//parents
	{
		close(fd[wr]);
		int y;
		if (read (fd[rd], &y, sizeof(int)) == -1)//where your data will be stored
		{
			perror("There is a error in the reading from the pipe :");
			printf("\n");
			return(3);
		}
		close(fd[rd]);
		printf("The data has been read perfectly and stored : %d\n", y);
	}
	return 0;
} 