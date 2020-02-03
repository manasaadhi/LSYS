#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	fd=open("/tmp/FIFO",O_RDONLY);
	if(fd<0)
	{
		perror("Open fails..");
		return -1;
	}
	printf("fd:%d\n",fd);
	char write_buf[50]="I am fine...";
	char read_buf[50];

	read(fd,read_buf,sizeof(read_buf));
	printf("%s\n",read_buf);
	close(fd);
	fd=open("/tmp/FIFO",O_WRONLY);
	if(fd<0){printf("Error\n");return -1;}
	write(fd,write_buf,sizeof(write_buf));
	close(fd);
}

