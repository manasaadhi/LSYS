#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
int mydiv(int,int);

void handel1(int signum)
{
	printf("signum:%d\n",signum);
	printf("denomonitor value is zero..\n");
	exit(-1);
}
int main()
{
	int x,y,ret;
	printf("Enter x,y values..\n");
	scanf("%d %d",&x,&y);
	signal(8,handel1);
	printf("x:%d   y:%d\n",x,y);
	ret=mydiv(x,y);
	printf("ret:%d\n",ret);
}
int mydiv(int a,int b)
{

	if(a<b)
		return b/a;
	else
		return a/b;
}
