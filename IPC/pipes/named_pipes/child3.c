#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	if((fd=open("/tmp/FIFO_File",O_RDONLY))<0)
	{
		perror("open fails..");
		return -1;
	}
	char read_buf[50];
	printf("fd:%d\n",fd);
	//getchar();
	if(read(fd,read_buf,sizeof(read_buf))<0)
		perror("read fails..");
	printf("%s\n",read_buf);

	close(fd);
}

