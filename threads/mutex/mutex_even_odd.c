#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void * Even(void*);
void * odd(void *);

int x=1;
pthread_mutex_t mutex;
int main()
{
	pthread_t id1,id2;
	if(pthread_create(&id1,NULL,&Even,NULL)<0)
	{
		perror("Thread1 fails...");
		return -1;
	}
	if(pthread_create(&id2,NULL,&odd,NULL)<0)
        {
                perror("Thread2 fails...");
                return -1;
        }
sleep(1);
//pthread_join(id1,NULL);
//pthread_join(id2,NULL);
	pthread_exit(NULL);
}
void * Even(void * a)
{
//	pthread_mutex_lock(&mutex);
	while(x<=11)
	{
		if(x%2==0)
		{
			printf("%d is even\n",x);
			x++;
		}
		
		//else
		//	pthread_mutex_unlock(&mutex);
		//x++;
	}
}
void * odd(void * a)
{
       // pthread_mutex_lock(&mutex);
        while(x<=11)
        {
                if(x%2!=0)
                {
			printf("%d is odd \n",x);
			x++;
		}
		
                //else
        	  //      pthread_mutex_unlock(&mutex);
	//x++;
	}
}

