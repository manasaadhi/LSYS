#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
//#define shm_key 0x1234
struct Message
{
	int status;
	int data[4];
};

int main()
{	
	struct Message * sh_addr;
	key_t shm_key;
        shm_key=ftok("file.txt",0);
	int shm_id;
	shm_id=shmget(shm_key,sizeof(struct Message),IPC_EXCL|0664);
	if(shm_id==-1)
	{
		perror("Shmget fails..");
		return -1;
	}
	printf("shmget success...\n");
	sh_addr=shmat(shm_id,NULL,0);
	if(sh_addr==(void *)-1)
	{
		perror("shmat failss...");
		return -1;
	}
	printf("shmat success\n");
//(sh_addr->status==1)
	{
		printf("%d\n",sh_addr->data[0]);	
		printf("%d\n",sh_addr->data[1]);	
		printf("%d\n",sh_addr->data[2]);	
		printf("%d\n",sh_addr->data[3]);	
	}
	sh_addr->status=0;
	/*if(shmdt((void *)sh_addr)==-1)
	{
		perror("shmdt fails...");
		return -1;
	}
	//printf("shmdt success..\n");*/
getchar();
}
