#include <semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
void * fun(void *);
void * fun2(void *);
void * fun3(void *);
void * fun4(void *);
int c=0;
sem_t mutex,mutex1;
pthread_mutex_t m;
int main()
{
	
	sem_init(&mutex,0,1);
	sem_init(&mutex1,0,1);
	pthread_t th1,th2,th3,th4;
	int ret;
	if(pthread_create(&th1,NULL,fun,NULL)<0)
	{
		perror("Thread1 fails...\n");
		return -1;
	}
	if(pthread_create(&th2,NULL,fun2,NULL)<0)
        {
                perror("Thread2 fails...\n");
                return -1;
        }
	 if(pthread_create(&th3,NULL,fun3,NULL)<0)
        {
                perror("Thread2 fails...\n");
                return -1;
        }
	/* if(pthread_create(&th4,NULL,fun4,NULL)<0)
        {
                perror("Thread2 fails...\n");
                return -1;
        }*/
pthread_exit(NULL);
//pthread_join(th1,NULL);
//pthread_join(th2,NULL);
//pthread_join(th3,NULL);
//pthread_join(th4,NULL);
}

void * fun(void * args)
{
	printf("Thread1....\n");
//	pthread_mutex_lock(&m);
	printf("Thread1 entered into critical section...\n");
	int i;
	for(i=0;i<10;i++)
	{
		printf("thread1_c:%d\n",c);
		c++;
	//sleep(2);
	}
	sem_wait(&mutex);
	//sem_post(&mutex);
	//pthread_mutex_unlock(&m);
}
void * fun2(void * args)
{

	sem_post(&mutex);
        printf("Thread2....\n");
	//pthread_mutex_lock(&m);
        printf("Thread2 entered into critical section...\n");
        int i;
        for(i=0;i<10;i++)
        {
		printf("thread2_c:%d\n",c);
                c++;
		//sleep(2);
        }
	sem_wait(&mutex1);
	//pthread_mutex_unlock(&m);
}
void * fun3(void * args)
{
	sem_post(&mutex1);
        printf("Thread3....\n");
	//pthread_mutex_lock(&m);
        printf("Thread3 entered into critical section...\n");
        int i;
        for(i=0;i<10;i++)
        {
                printf("thread3_c:%d\n",c);
                c++;
		//sleep(2);
        }
	//pthread_mutex_unlock(&m);
}
/*void * fun4(void * args)
{
        printf("Thread4....\n");
        //sem_wait(&mutex);
	pthread_mutex_lock(&m);
        printf("Thread4 entered into critical section...\n");
        int i;
        for(i=0;i<10;i++)
        {
                printf("thread4_c:%d\n",c);
                c++;
		//sleep(2);
        }
	//sem_post(&mutex);
	pthread_mutex_unlock(&m);
}*/

