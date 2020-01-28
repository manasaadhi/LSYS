#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void * fun(void * args)
{
	int * a;
	printf("I am in thread..\n");
//	a=(int *)args;
	//printf("a:%d\n",*a+2);
}
int main()
{
	pthread_t thread_id;
	int ret,a=5;
	ret=pthread_create(&thread_id,NULL,&fun,NULL);
	/*if(ret==0)
	{
		printf("Thread successfully created...\n");*/
		//pthread_join(thread_id,NULL);
	
	/*else
	{
		printf("Thread is not crerated...\n");
		return 0;
	}*/
	return 0;
}

