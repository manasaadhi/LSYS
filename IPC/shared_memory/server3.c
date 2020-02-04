#include <sys/types.h>
#include <sys/ipc.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/shm.h>
//#define shm_key 0x1234
struct Message
{
	int status;
	int data;
};

int main()
{
	struct Message *sh_addr;
	key_t shm_key;
	shm_key=ftok("file.txt",0);
	int shm_id;
	shm_id=shmget(shm_key,sizeof(struct Message),IPC_CREAT|0664);
	if(shm_id==-1)
	{
		perror("shared memory fails..");
		return -1;
	}
	printf("Shared memory created successfully...\n");
	sh_addr=shmat(shm_id,NULL,0);
	if(sh_addr==(void *)-1)
	{
		perror("shared memory attachment fails..");
		return -1;
	}
	printf("shmattach successs...\n");
	getchar();
	int i;

	for(i=0;;i++)
	{
	printf("Enter data..\n");
		//if(sh_addr->status==0)
			scanf("%d",&sh_addr->data);
		//sh_addr->status=1;
		if(sh_addr->data==-1)
			break;
//tchar();
	}
	if(shmdt((void*)sh_addr)==-1)
	{
		perror("shmdt fails..");
		return -1;
	}
	printf("shmdt success...\n");
	
}


