#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void * f1(void *);
void * f2(void *);
int x=-5;
pthread_mutex_t mutex;

int main()
{
	pthread_t id1,id2;
	if(pthread_create(&id1,NULL,f1,NULL)<0)
	{
		perror("Thread1 fails..");
		return -1;
	}
	if(pthread_create(&id2,NULL,f2,NULL)<0)
        {
                perror("Thread2 fails..");
                return -1;
        }
pthread_exit(NULL);
}
void * f1(void * args)
{
printf("Thread1..\n");
	pthread_mutex_lock(&mutex);
	if(x<0)
	{
		printf("Negative..\n");
		x++;
	}
	else
		printf("Its incremented...\n");
	//pthread_mutex_unlock(&mutex);
}
void * f2(void * args)
{
printf("Thread2...\n");	
	pthread_mutex_lock(&mutex);
	
	if(x>0)
	{
		printf("Positive...\n");
	}
	else
	{
		while(x<0)
		{
			printf("X:%d\n",x);
			x++;
		}
			
	}
	pthread_mutex_unlock(&mutex);
}
