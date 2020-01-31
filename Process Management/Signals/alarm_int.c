#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include <stdlib.h>

int seconds(int h,int m,int s)
{
int sec=0;
sec+=h*3600;
sec+=m*60;
sec+=s;

return sec;
}
//For this we have to install sox and sox libsox-fmt-all
void myhandler(int signum)
{
if(signum==SIGALRM)
	system("play ./song.mp3");
if(signum==SIGINT)
	printf("Interrupt signal\n");
}

int main(void)
{
int h,m,s;
signal(SIGALRM,myhandler);
signal(SIGINT,myhandler);
//printf("Enter HH:MM:SS\n");
//scanf("%d:%d:%d",&h,&m,&s);
alarm(2);
while(1);
return 0;
}

