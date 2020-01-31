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
void my_alarm(int sig_num)
{
system("play ./song.mp3");
}

int main(void)
{
int h,m,s;
signal(SIGALRM,my_alarm);
printf("Enter HH:MM:SS\n");
//scanf("%d:%d:%d",&h,&m,&s);
alarm(2);
while(1);
return 0;
}

