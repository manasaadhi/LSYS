#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int pipe_fds[2];
	char write_msg[3][20]={"hii","hello","everyone"};
	char read_msg[20];
	if(pipe(pipe_fds)==-1)
	{
		perror("pipe fails...\n");
		return -1;
	}
	int pid;
	pid=fork();
	if(pid==-1)
	{
		perror("fork fails..\n");
		return -1;
	}
	else if(pid==0)
	{
		read(pipe_fds[0],read_msg,sizeof(read_msg));
		printf("Message1_child:%s\n",read_msg);
	getchar();
		read(pipe_fds[0],read_msg,sizeof(read_msg));
		printf("Message2_child:%s\n",read_msg);
	getchar();
		read(pipe_fds[0],read_msg,sizeof(read_msg));
		printf("Message3_child:%s\n",read_msg);
	getchar();
		write(pipe_fds[1],"Thankyou",sizeof("Thankyou"));
		
	}
	else
	{
		write(pipe_fds[1],write_msg[0],sizeof(write_msg));	
	getchar();
		write(pipe_fds[1],write_msg[1],sizeof(write_msg));
	getchar();
		write(pipe_fds[1],write_msg[2],sizeof(write_msg));	
	getchar();
		read(pipe_fds[0],read_msg,sizeof(read_msg));
		printf("Message_parent:%s\n",read_msg);
	}
	return 0;
}
