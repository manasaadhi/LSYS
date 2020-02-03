#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	mkfifo("/tmp/FIFO",0664);
	int fd;
	fd=open("/tmp/FIFO",O_WRONLY);
	if(fd<0)
	{
		perror("Open fails..");
		return -1;
	}
	printf("fd:%d\n",fd);
	char write_buf[50]="How are you?";
	char read_buf[50];

	write(fd,write_buf,sizeof(write_buf));
close(fd);
//getchar();
	fd=open("/tmp/FIFO",O_RDONLY);
/*if(fd<0)
	{printf("Error\n");return -1;}*/
	read(fd,read_buf,sizeof(read_buf));
		printf("%s\n",read_buf);
close(fd);
}

