#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int c=0;
pthread_mutex_t mutex;
void * fun(void *);
void * fun2(void *);
void * fun3(void *);
int main()
{
	pthread_t id1,id2,id3;
	if(pthread_create(&id1,NULL,fun,NULL)<0)
	{
		perror("Thread fails...");
		return -1;
	}
	//pthread_join(id1,NULL);
	if(pthread_create(&id2,NULL,fun2,NULL)<0)
        {
                perror("Thread2 fails...");
                return -1;
        }
	//pthread_join(id2,NULL);
	if(pthread_create(&id3,NULL,fun3,NULL)<0)
        {
                perror("Thread3 fails...");
                return -1;
        }
	//pthread_join(id3,NULL);

printf("Bye..\n");

pthread_exit(NULL);
}

void * fun(void * a)
{
	//printf("In Thread 1 c is:%d\n",c);
	int i=0;
	pthread_mutex_lock(&mutex);
	while(i<100)
	{
		c++;
		i++;
		printf("Thread1 c is:%d\n",c);
		sleep(3);
	}
	pthread_mutex_unlock(&mutex);
}
void * fun2(void * a)
{
        //printf("In Thread 2 c is:%d\n",c);
       int i=0;
	pthread_mutex_lock(&mutex);
	 while(i<100)
        {
                c++;
                i++;
		printf("Thread2 c is:%d\n",c);
		sleep(3);
        }
	pthread_mutex_unlock(&mutex);
}
void * fun3(void * a)
{
        //printf("In Thread 3 c is:%d\n",c);
        int i=0;
	pthread_mutex_lock(&mutex);
	while(i<100)
        {
                c++;
                i++;
		printf("Thread3 c is:%d\n",c);
		sleep(3);
        }
	pthread_mutex_unlock(&mutex);
}
