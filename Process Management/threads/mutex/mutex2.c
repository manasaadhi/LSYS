#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


void * fun(void *);
void * fun2(void *);
void * fun3(void *);

int c=0;
pthread_mutex_t mutex;

int main()
{
	pthread_t id1,id2,id3;
	if(pthread_create(&id1,NULL,fun,NULL)<0)
	{
		perror("Thread1 fails...");
		return -1;
	}
	if(pthread_create(&id2,NULL,fun2,NULL)<0)
        {
                perror("Thread2 fails...");
                return -1;
        }
	if(pthread_create(&id3,NULL,fun3,NULL)<0)
        {
                perror("Thread3 fails...");
                return -1;
        }

	//pthread_join(id1,NULL);
	//pthread_join(id2,NULL);
	//pthread_join(id3,NULL);
pthread_exit(NULL);
}

void * fun(void * a)
{
	int i=0;
	    //pthread_mutex_lock(&mutex);
	for(i;i<10;i++,c++)
		printf("Increment in thread1:%d\n",c);
	    //pthread_mutex_unlock(&mutex);
	printf("At the end of thread1..\n");
}
void * fun2(void * args)
{
	int i;
//	pthread_mutex_lock(&mutex);
	for(i=0;i<10;i++,c--)
		printf("decrement in thread2:%d\n",c);
//		pthread_mutex_unlock(&mutex);
	printf("At the end of thread2..\n");
	sleep(10);
}

void * fun3(void * b)
{
	int i;
	//pthread_mutex_lock(&mutex);
	for(i=0;i<10;i++,c-2)
		printf("In thread3:%d\n",c);
	//pthread_mutex_unlock(&mutex);
	printf("At the end of thread3..\n");
}
