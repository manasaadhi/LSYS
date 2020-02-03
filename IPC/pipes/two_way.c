#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int pipe1fds[2],pipe2fds[2];
//	char write1_msg[20]="Hello world";
	char write2_msg[20]="Good morning";
	char read1_msg[20];
	char read2_msg[20];
	if(pipe(pipe1fds)==-1)
	{
		perror("pipe fails...");
		return -1;
	}
	if(pipe(pipe2fds)==-1)
	{
		perror("pipe fails...");
		return -1;
	}
	int pid;
	pid=fork();
	if(pid==-1)
	{
		perror("fork fails...");
		return -1;
	}
	else if(pid==0)
	{
		int pid;
		pid=fork();
		if(pid==0)
		{
			char write1_msg[40]="Manasa is good girl";
			printf("grand child\n");		
		read(pipe2fds[0],read2_msg,sizeof(read2_msg));
		printf("Message_grand child:%s\n",read2_msg);
		//write(pipe1fds[1],write1_msg,sizeof(write1_msg));
			return 0;	
		}
		else
		{
		read(pipe1fds[0],read1_msg,sizeof(read1_msg));
		printf("Message_child:%s\n",read1_msg);
		write(pipe2fds[1],read1_msg,sizeof(read1_msg));
		printf("child..\n");
			wait(NULL);
		}
	}
	else
	{
		printf("Parent..\n");
		//write(pipe1fds[1],write1_msg,sizeof(write1_msg));
		read(pipe2fds[0],read2_msg,sizeof(read2_msg));
		printf("Message_parent:%s\n",read2_msg);
		wait(NULL);
	}
}
