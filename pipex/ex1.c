#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char* argv[])
{
	int id1 = fork();
	int id2 = fork();

	if ( id1 == 0)//i am in the child process
	{
		if (id2 == 0)
		{
			printf("this is y\n");
			// wait(NULL) != -1;
		}
		else{
			printf("this is the x\n");
			// wait(NULL) != -1;
		}
	}
	else{//parents and z process
		if(id2 == 0)
		{
			printf("this is z\n");
			// wait(NULL) != -1;
		}
		else{
			printf("parents process\n");
			// wait(NULL) != -1;
		}
	}
	//when it is only wait(NULL), it will only terminate z process first and later parents process. So other 2 y,z process will be remined.
	//to avoid it you should use while and errono != ECHILD to specify until there is no child.

/*parents process
this is z
this is the x
this is y*///hierachy from top to down
	while(wait(NULL) != -1 || errno != ECHILD) 
	{
		printf("wait for a child to finish\n");
	}
	return(0);
}
