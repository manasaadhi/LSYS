#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>

void* fun(void *);
int main()
{
	pthread_t thread_id,thread_id2,thread_id3;
	int ret;

	if((ret=pthread_create(&thread_id,NULL,fun,NULL))<0)
	{
		perror("thread creation fails..");
		return -1;
	}
	printf("Thread is successfully created....\n");
	//pthread_join(thread_id,NULL);
	printf("Thread ended..\n");
	if((ret=pthread_create(&thread_id2,NULL,fun,NULL))<0)
	{
		perror("thread creation fails..");
		return -1;
	}
	printf("Thread is successfully created....\n");
	if((ret=pthread_create(&thread_id3,NULL,fun,NULL))<0)
        {
                perror("thread creation fails..");
                return -1;
        }
        printf("Thread is successfully created....\n");

}

void* fun(void * arg)
{
	printf("Thread function...\n");
}
