#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"
#include "windows.h"
#define M   20
typedef struct
{
	int a[M];//共享栈的长度
	int top[2];//栈顶两个
}Stack;
void InitStack(Stack *aa)//共享栈的初始化
{
	aa->top[0] = -1;/*初始化两个栈顶*/
	aa->top[1] = M;
}
//进栈
int Push(Stack *aa, int x, int y)//进哪个栈，进栈元素是谁
{
	if (aa->top[0] + 1 == aa->top[1])//栈满
	{
		printf("栈满");
		return 1;
	}
	if (x != 0 && x != 1)
	{
		printf("选择的栈不存在");
		return 1;
	}
	switch (x)
	{
	case 0://进top[0];
		aa->top[0]++;
		aa->a[aa->top[0]] = y;//共享栈上的top[0]赋值  ，这里就是跟普通栈的区别了
		break;
	case 1://进top[1]
		aa->top[1]--;
		aa->a[aa->top[1]] = y;//共享栈上的top[1]赋值  ，这里就是跟普通栈的区别了
		break;
	defalut:
		return 1;//默认错误返回
	}
	return 0;
}
int main()
{
	Stack aa = { {0},-1 }, *aa1; aa1 = &aa; int i;
	InitStack(aa1);
	Push(aa1, 1, 10);
	for (i = -0; i < M; i++)
	{
		printf("%d\n", aa1->a[i]);
	}

	system("pause");
	return 0;
}