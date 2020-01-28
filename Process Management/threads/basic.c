#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void* fun(void * args)
{
	printf("Inside Thread\n");
}

int main()
{
	pthread_t id;
	int ret;
	ret=pthread_create(&id,NULL,&fun,NULL);
	if(ret==0)
	{
		printf("thread successfully created\n");
		pthread_join(id,NULL);
	}
	else
	{
		printf("thread is not created succefully\n");
		return -1;
	}

}
