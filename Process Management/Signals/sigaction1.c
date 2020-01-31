#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
 #include <unistd.h>
void handler(int signum)
{
	if(signum==2)
	{
	printf("Interrupt signal...\n");
	//sleep(15);
	}
	if(signum==11)
	{
		printf("segmenation fault signal...\n");
	//	sleep(5);
		kill(2,getpid());
	}
}
int main()
{
	struct sigaction sa;
	sa.sa_handler=&handler;
	sa.sa_flags = SA_NODEFER|SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(2,&sa,NULL);
	sigaction(11,&sa,NULL);
	int i;
printf("Enter i\n");
	scanf("%d",i);
	while(1)
	{
		sleep(1);
	}
	
}
