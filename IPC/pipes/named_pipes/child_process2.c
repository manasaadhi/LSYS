#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <fcntl.h>
int main()
{
	int fd;
	fd=open("/tmp/myfifo",O_WRONLY);
	if(fd<0)
	{
		perror("open fails..");
		return -1;
	}
	char write_buf[50];
	while(1)
	{
	scanf("%s",write_buf);
	if((strcmp(write_buf,"end"))==0)
		return 0;
	write(fd,write_buf,sizeof(write_buf));
		//printf("%s",read_buf);
	}
}

