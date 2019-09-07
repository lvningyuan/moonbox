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
	printf("**1 乘法****2  除法***\n");
	printf("**3 加法****4  减法***\n");
	printf("**********************\n");
	printf("请选择\n");
	scanf("%d",&a);
	printf("请输入两个操作数\n");
	scanf("%d%d",&x,&y);
	while( a>=1 && a<=4)
	{
		(*arr[a]) (x,y);
		break;
	}
	printf("输入无效，请重新输入\n");
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