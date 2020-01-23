#include<stdio.h>

union test
{
	int i;
	char c[4];
};


int main()
{
	union test u;
	u.i=16;
	int j;
	//for(j=0;j<4;j++)
		printf("%p    %p\n",&u.c[0],&u.c[3]);
		printf("%d    %d\n",u.c[0],u.c[3]);
	//printf("i:%d\n",u.i);
}
