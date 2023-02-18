#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
//#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t id = fork();
	int n;

	if(id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
	if(id != 0)
	{
		wait(NULL); // for the macOS you should fill the parameter
		//because wait works when you wait for the child process
		//if you just put wait() with out that condition,
		//the child process itself will also waiting for its child process 
		//even it does not have one, then stuck at there and never get ended. 
	}
	int i;
	for(i = n; i < n + 5; i++)
	{
		printf("%d", i);
		//when you call printf, it will save in buffer and then print it out.
		//but when you want to print it out every each time then you use fflush(stdout);
		fflush(stdout);
	}
	//if you want to have only one line then
	if ( id != 0)
	{
		printf("\n");
	}
	return 0;
}
//the order can be completely changed everytime you call it