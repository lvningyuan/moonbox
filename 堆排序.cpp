#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
#include "windows.h"
void Mysift(int * a, int k, int num);
void Myheapsort(int * a, int num);
void Mycreate(int *a, int num);
void Myheapsort(int * a, int num)//实现每次得到一个最大尾数,
{
	int i; int tmp; 
	Mycreate(a,num);
	for (i = num - 1; i > 0; i--)//控制排序趟数num-1趟
	{
		tmp = a[i];
		a[i] = a[0];//每趟初始大根堆的大根位于a[0]位置
		a[i] = tmp;
		Mysift(a,i-1,num);//每取出一个最大值重新排队
	}
	
}
void Mycreate(int *a, int num)//建初堆 
{
	int i;
	for (i = num / 2; i >=0; i--)
	{
		Mysift(a,i,num);//从第i个到第num个关键字重新排序
	}
}
	//重建堆 //目的是为了将堆内的数据顺序化，大的放在双亲结点，
void Mysift(int * a, int k, int num)
{
	int tmp = a[k];//将a[0]保存下来，然后a[0]置空
	int i=k;
	int j = 2 * i;
	int flg = 0;//树立标杆
	while (j < num && flg != 1)//不超越数组范围内,不能已经排好
	{ 
		if (j + 1 <= num && a[j] < a[j + 1])//若左孩子小于右孩子
			j = j + 1;
		if (a[k] >= a[j])//满足准备跳出
		{
			flg = 1;//标杆改变
		    break; 
		}
		else//这种情况是为后续弹出堆顶元素后做准备，第一趟其实不影响
		{
			a[i] = a[j];
			i = j;         //继续帅选
		    j = 2 * i;
		}
	}
	a[i] = tmp;
}
int main()
{
	int a[] = { 3,4,6,1,2,1,5,1,0 };
	int num = sizeof(a) / sizeof(int);
	int i;
	//调用一次快排
	//MyQsort(a, num);//k接受一趟快排的基准下表
   //左边再快排
	Myheapsort(a,num);
	for (i = 0; i < num; i++)
	{
		printf("%d\n",a[i]);
	}

	system("pause");
	return 0;
}
