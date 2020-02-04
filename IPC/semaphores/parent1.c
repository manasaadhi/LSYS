#include <sys/ipc.h>
#include<unistd.h>
#include <sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#define shm_key 0x45678
#define sem_key 0x9874
int c=0;

int main()
{
	int * p;
	int shm_id;
	shm_id=shmget(45678,sizeof(c),IPC_CREAT|0664);
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
	*p=0;
	while(i<10)
	{
		
		(*p)++;i++;
		sleep(1);
	}
}



