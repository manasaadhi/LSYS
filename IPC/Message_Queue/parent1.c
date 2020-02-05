#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct my_msgbuf 
{
	long mtype;       /* message type, must be > 0 */
        char mtext[100];    /* message data */
 };


int main()
{
	struct my_msgbuf buf;
	key_t msg_key;int msg_id;
	msg_key=ftok("file.txt",0);
	if((msg_id=msgget(msg_key,IPC_CREAT|0664))==-1)
	{
		perror("Message queue fails");
		return -1;
	}
	printf("msgget success..\n");
//	printf("Enter data\n");
	//scanf("%s",buf.mtext);
	strcpy(buf.mtext, "This is a general message");
	int len;	
	len=strlen(buf.mtext);
	buf.mtype=1;
	if(msgsnd(msg_id,&buf,len+1,0)==-1)
	{
		perror("msgsnd fails..");
		return -1;
	}
	printf("msgsnd success..\n");
	
}

