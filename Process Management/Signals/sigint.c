#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
void handler(int signum)
{
	if(signum==2)
	{
	printf("Interrupt signal...\n");
	sleep(3);
	}
	if(signum==11)
	{
		printf("segmenation fault signal...\n");
		sleep(5);
	}
}
int main()
{
	signal(2,handler);
	signal(11,handler2);
	int i;
	scanf("%d",i);
	while(1)
	{
		sleep(1);
	}
	
}
