#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>

int main()
{
	close(1);
	printf("Manasa\n");
	close(2);
	int fd1,fd2;
	fd1=open("output.txt",O_WRONLY);
	fd2=open("error.txt",O_WRONLY);
	int *p=NULL;
	printf("writing to null\n");
	perror("checking error");
	
}






