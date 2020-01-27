#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


void * fun1(void *);
void * fun2(void *);

int main()
{
	pthread_t thread_id1,thread_id2;
	int ret1,ret2;
	if((ret1=pthread_create(&thread_id1,NULL,fun1,NULL))<0)
	{
		perror("thread1 fails..\n");
		return -1;
	}
	printf("Thread1 created...\n");
	pthread_join(thread_id1,NULL);
	printf("thread1 completed...\n");
		sleep(2);
	//pthread_exit(NULL);

	if((ret2=pthread_create(&thread_id2,NULL,fun2,NULL))<0)
        {
                perror("thread2 fails..\n");
                return -1;
        }
	printf("Thread2 created...\n");
	
	pthread_join(thread_id2,NULL);

	printf("thread2 completed...\n");
//	sleep(2);
	pthread_exit(NULL);
printf("programm end...\n");

}



void * fun1(void * arg)
{
	pthread_t id;
	printf("Hello I am Thread1...\n");
	id=pthread_self;
	printf("id1:%lld\n",id);
}
void * fun2(void * a)
{
	pthread_t id;
	id=pthread_self;
	printf("Hello I am Thread2...\n");
	printf("id:%lld\n",id);
}
