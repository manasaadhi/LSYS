#include <sys/sem.h>
#include <sys/ipc.h>
#include<unistd.h>
#include <sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#define shm_key 0x234
#define sem_key 0x9874
//int c=0;

int main()
{
	int * p;
	int shm_id;
	struct sembuf sem_buf;
	shm_id=shmget(shm_key,sizeof(int),IPC_EXCL|0664);
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
	//*p=0;
	int sem_id,sem_op;
		sem_id=semget(sem_key,1,IPC_CREAT|0664);
	if(sem_id==-1)
	{
		perror("semget fails..");
		return -1;
	}
	printf("semget success\n");

	while(i<11)
	{
		sem_buf.sem_num=0;
		sem_buf.sem_op=-1;
		sem_buf.sem_flg=SEM_UNDO;
		sem_op=semop(sem_id,&sem_buf,1);
		if(sem_op==-1)
		{
			perror("semop lock fails...");
			return -1;
		}	
		printf("lock success and it enter into critical section\n");
		printf("%d\n",*p);
		//sleep(1);
		if(i==10)
		{
			sem_buf.sem_num=0;
                sem_buf.sem_op=1;
                sem_buf.sem_flg=SEM_UNDO;
                sem_op=semop(sem_id,&sem_buf,1);
                if(sem_op==-1)
                {
                        perror("semop lock fails...");
                        return -1;
                }       
                printf("unlock successful\n");

		}
	}
}



