#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	if((fd=open("/tmp/FIFO_File",O_WRONLY))<0)
	{
		perror("open fails..");
		return -1;
	}
	//fd=open("/tmp/FIFO_File",O_WRONLY);
	
	char write_buf[50]="Hello Mirafra Team";
	printf("fd:%d\n",fd);
	//getchar();
	if(write(fd,write_buf,sizeof(write_buf))<0)
		perror("write fails..");
	else
		printf("\nwriting success...\n");
	close(fd);
}

