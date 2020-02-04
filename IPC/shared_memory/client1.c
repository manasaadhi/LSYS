#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
//#define shm_key 0x1234
struct Message
{
	int status;
	int data;
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
	int i;
	for(i=0;;i++)
	{
		if(sh_addr->data==-1)
		{
                        //printf("data:%d\n",sh_addr->data);
			shmdt((void *)sh_addr);
			printf("shmdt success...\n");
			return 0;
		}
                        printf("data:%d\n",sh_addr->data);

	}
}
