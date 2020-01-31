#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int status,pid;
	pid=vfork();
	if(pid<0)
	{
		perror("fork fails...");
		return -1;
	}
	else if(pid==0)
	{
		printf("Child..\n");
	//	getchar();
	}
	else
	{
		printf("parent...\n");
		//getchar();
	//	wait(&status);
	}
}
