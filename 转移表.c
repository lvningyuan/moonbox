#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
#include"windows.h"
void add(int x,int y)
{
     printf("x  +  y  ==%d",x+y);
}
void sub(int x,int y)
{
     printf("x  -  y  ==%d",x-y);
}
void mul(int x,int y)
{
     printf("x  *  y  ==%d",x*y);
}
void dev(int x,int y)
{
     printf("x  /  y  ==%d",x/y);
}
void main ()
{
	int a;int x,y; void (* arr[5])(int,int)={0,mul,dev,add,sub};
	printf("**********************\n");
	printf("**1 �˷�****2  ����***\n");
	printf("**3 �ӷ�****4  ����***\n");
	printf("**********************\n");
	printf("��ѡ��\n");
	scanf("%d",&a);
	printf("����������������\n");
	scanf("%d%d",&x,&y);
	while( a>=1 && a<=4)
	{
		(*arr[a]) (x,y);
		break;
	}
	printf("������Ч������������\n");
	/*if(a == 1)
	{
	mul(x,y);
	}
	if(a == 2)
	{
	div(x,y);
	}
	if(a == 3)
	{
	add(x,y);
	}
	if(a == 4)
	{
	sub(x,y);
	}*/
	system("Pause");
}