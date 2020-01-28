#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void * fun1(void *);
void * fun2(void *);
int main()
{
	pthread_t thread_id1,thread_id2;
	int ret1,ret2;
	if(pthread_create(&thread_id1,NULL,fun1,NULL)<0)
	{
		perror("Thread1 fails...\n");
		return -1;
	}
	printf("Thread1 created...\n");
	if(pthread_create(&thread_id2,NULL,fun2,NULL)<0)
        {
                perror("Thread2 fails...\n");
                return -1;
        }
        printf("Thread2 created...\n");
	pthread_join(thread_id2,NULL);
printf("Bye...\n");

}


void * fun1(void * args)
{
	int i=0;
	printf("Thread1....\n");
	pthread_detach(pthread_self());
	while(i<10)
	{	printf("i:%d\n",i);
		i++;
	}
sleep(20);
}
void * fun2(void * arg)
{
	int j=0;
	printf("Thread2....\n");
	//sleep(20);
	for(j=0;j<10;j++)
		printf("j:%d\n",j);
	
}
