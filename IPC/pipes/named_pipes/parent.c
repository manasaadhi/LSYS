#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int mkfifo_ret;
	mkfifo("/tmp/FIFO_File",0666);
	/*{
		perror("mkfifo fails...");
		return -1;
	}*/
	char write_buf[50]="How are you all?";
	int fd;
	fd=open("/tmp/FIFO_File",O_WRONLY);
	if(fd<0)
	{
		perror("Open fails..");
		return -1;
	}
	printf("fd:%d\n",fd);
	getchar();
	if(write(fd,write_buf,sizeof(write_buf))<0)
		perror("write fails...\n");
	else
		printf("write success\n");
	close(fd);
}

