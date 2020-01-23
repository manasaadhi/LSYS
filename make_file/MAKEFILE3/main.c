#include<stdio.h>
//#include"./myheadder.h"
int add(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);
int main()
{
	int a,b,ch;
	printf("enter a,b values\n");
	scanf("%d%d",&a,&b);
	printf("add:%d\n",add(a,b));
	printf("sub:%d\n",sub(a,b));
	printf("mul:%d\n",mul(a,b));
	printf("div:%d\n",div(a,b));
}
