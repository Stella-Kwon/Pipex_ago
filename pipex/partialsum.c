#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	//even the process is starting at the same time parallel.
	//but you need to be careful to wait for receiving the child process termination status 
	int array [] = {1, 2, 3, 4, 1, 2};
	int arrsize = sizeof(array)/sizeof(int); //very useful in if it has very large elements.
	int start, end;
	int fd[2];

	if (pipe(fd) == -1)
	{
		perror("Pipe Error :\n");
		return 1;
	}
	int pid = fork();
	if(pid == -1)
	{
		printf("Fork error : %s\n", strerror(errno));
		return 2;
	}
	if (pid == 0)
	{
		start = 0;
		end = arrsize/2;
	}
	else
	{
		start = arrsize/2;//you cannot use end because it will give some random like 1 number to it.
		end = arrsize;
	}
	int i;
	int sum = 0;
	for (i = start; i < end; i++) //THE SAME PROCESS FORMULA. so it is not in code block
		{
			//int sum;//if you call the same one again and give nothing value it will not work any. as it needs to keep + on the intial value
			sum += array[i]; 
		}
	printf("Partial sum : %d\n", sum);                           

	if (pid == 0)
	{	
		close(fd[0]);
		if( write(fd[1], &sum, sizeof(sum)) == -1)
		{
			perror("write error to pipe for child process :\n");
			return 3;
		}
		close(fd[1]);
	}
	else
	{
		int sumfromchild = sum;// you can only call the sumfromchild in this codeblock
		close(fd[1]);
		if (read(fd[0], &sumfromchild, sizeof(sumfromchild)) == -1)
		{
			printf("Error form reading pipe from child : %s\n", strerror(errno));
			return 4;
		}
		close(fd[0]);
		int totalsum = sum + sumfromchild;
		printf("Total sum is : %d\n", totalsum);
		wait(NULL);//wait until child process finish(you recieve status from child)
	}
	return 0;
}