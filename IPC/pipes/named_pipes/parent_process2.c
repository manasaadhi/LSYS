#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	mkfifo("/tmp/myfifo",0666);
	int fd;
	fd=open("/tmp/myfifo",O_RDONLY);
	if(fd<0)
	{
		perror("open fails..");
		return -1;
	}
	char read_buf[50];
	while(1)
	{	
		getchar();
	if((strcmp(read_buf,"end")==0))
		exit(0);
	read(fd,read_buf,sizeof(read_buf));
		printf("%s",read_buf);
	}
}

