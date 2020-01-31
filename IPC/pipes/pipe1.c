#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main()
{
	int pipefd[2];
	char write_arr[2][10]={"hello","world"};
	char read_arr[10];
	if(pipe(pipefd)==-1)
	{
		perror("pipefails...");
		return -1;
	}
	printf("Pipe successs..\n");
	if(write(pipefd[1],write_arr[0],sizeof(write_arr))==-1)
		perror("write fails...\n");
	if(read(pipefd[0],read_arr,sizeof(read_arr))==-1)
                perror("read fails...\n");
	printf("reading message:%s\n",read_arr);

		
}
