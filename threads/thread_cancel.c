#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void * fun1(void *);
int main()
{
	pthread_t id1,id2;
	
	if(pthread_create(&id1,NULL,fun1,NULL)<0)
	{
		perror("Thread fails...");
		return -1;
	}
	printf("Thread sucessfully created....\n");
	if(pthread_cancel(id1)>0)
		perror("Thread cancellation is disabled...");
			
	
}

void * fun1(void * args)
{
	getchar();
	printf("I am in Thread...\n");

}
