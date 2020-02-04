#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#define shm_key 45678
#define sem_key 0x9874
int c;

int main()
{
	int * p;
	int shm_id;
	shm_id=shmget(shm_key,sizeof(c),IPC_EXCL|0664);
	if(shm_id==-1)
	{
		perror("shmget fails..");
		return -1;
	}	
	printf("shmget success\n");
	p=shmat(shm_id,NULL,0);
	if(p==(void *)-1)
	{
		perror("shmat fails..");
		return -1;
	}
	printf("shmat success..\n");
	int i=0;
	while(i<10)
	{
		printf("%d\n",*p);
		sleep(2);i++;
		
	}
}



