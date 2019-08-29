#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include"windows.h"
#include"math.h"
//青蛙跳台阶1一次一层两层
int Sum(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	int sum = 0; 
	int a = 1;
	int b = 2;
	for (int i = 3; i <= n; i++)
	{
		sum = a + b ;
		a=b;
		b = sum;
	}
	return  sum;
}
//变态跳台阶
//每次任意跳层数
//我们分析  1 层 1种
//2 层两种
//3层4种
//n层  2^(n-1)种
//  或者 f(n)对应f(n-1)+....+f（1）种选择；而每个f(n以内也是)所以总数数为2f(n-1)种
//  这里的f(n-1)意思为从第n-1层跳到第n层
//所以我们直接调用库函数
int Sum2(int n)
{
	int sum = (int)pow((double)2, (double)(n - 1));
		return sum;
}
int main()
{
	int  n;
	printf("请输入台阶数");
	while (scanf("%d", &n))
	{
		int ret = Sum(n);
		int ret2 = Sum2(n);
		printf(" 每次 跳1 或 2 层共%d\n", ret);
		printf("变态跳共： %d\n", ret2);
	}
	system("pause");
	return 0;
}


