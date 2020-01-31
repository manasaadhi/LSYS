#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
	int pipefd[2],PID;
	char write_msg[2][20]={"Hii","Hello"};
	char read_msg[20];
	if(pipe(pipefd)==-1)
	{
		perror("pipe fails..\n");
		exit(-1);
	}
	PID=fork();
	if(PID==-1)
	{
		perror("fork fails..\n");
		return -1;
	}
	if(PID>0)
	{
	if((write(pipefd[1],write_msg[0],sizeof(write_msg))==-1))
		perror("write fails...\n");
	if((write(pipefd[1],write_msg[1],sizeof(write_msg))==-1))
		perror("write fails...\n");
	
	}
	if(PID==0)
	{
	if((read(pipefd[0],read_msg,sizeof(read_msg))==-1))
		perror("read fails...\n");
	printf("Message1:%s\n",read_msg);
	if((read(pipefd[0],read_msg,sizeof(read_msg))==-1))
		perror("write fails...\n");
	printf("Message2:%s\n",read_msg);
	}
	
}
