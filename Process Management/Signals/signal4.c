#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
void handle(int signum)
{
	printf("segmentaion fault error\n");
//	exit(-1);
}
void handle2(int signum)
{
	printf("alaram signal\n");
//	exit(0);
}

int main()
{
	int x;
	signal(11,handle);
	signal(14,handle2);
	alarm(1);	
	printf("Enter x value\n");
	scanf("%d",x);

}
