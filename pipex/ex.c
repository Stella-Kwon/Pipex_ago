#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	int ID = fork();
	if(ID == 0)
		sleep(1);
	//sleep for 1second. 
	//which parents and child processes initiate at the same time and the parents processor alway ends first,
	//but when you slow the child process then it will give you some problem. doenst really get terminated in the parents process.
	printf("current id : %d, parents id : %d\n",getpid(), getppid());

	if(ID != 0)
	{
		wait(NULL); 
	}
	int res = wait(NULL);
	// it is working for the both process again.
	// so after you mentioned on top wait 
	//so for the parents also have no child process to wait for. because it is already terminated
	//you get process id of what you waited for. parent id
	if (res == -1)//-1 means there is no child process to wait.
	{
		printf("There is no child process to wait for :\n %s\n", strerror(errno));
		//to print the sterror out you need to call %s specifier in printf.
		perror("NO child :\n");
		//strerror(errno);// it will do nothing.
	}
	else
	{
		printf("%d finished execution\n", res);
	}
	
	return (0);

	//use wait when they have multiple children process.
	//u need to use wait. when you use fork.
}
