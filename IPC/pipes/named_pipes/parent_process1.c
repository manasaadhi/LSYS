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
	char read_buf[50];
	int fd;
	fd=open("/tmp/FIFO_File",O_RDONLY);
	if(fd<0)
	{
		perror("Open fails..");
		return -1;
	}
	printf("fd:%d\n",fd);
	if(read(fd,read_buf,sizeof(read_buf))<0)
		perror("read fails...\n");
	else
		printf("%s\n",read_buf);
	close(fd);
}

