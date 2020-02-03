#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	close(1);
	int fd;
	fd=open("abc.txt",O_WRONLY);
	if(fd<0)
	{
		perror("open fails..");
		return -1;
	}
	printf("fd:%d\n",fd);
	int i;
	for(i=0;i<5;i++)
	{
		printf("Hello alliiiiiiiiii sirrrrrrr\n");
	}
return 0;
}
