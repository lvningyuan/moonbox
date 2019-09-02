查找丑数的2种方法   
第一种  牺牲空间换取时间  第二种 牺牲时间，挨着判断

什么是丑数 ？  

一个数能被 2   3   5 整除，因子只能包含2  3  5  即 被这3个数了反复除后商为1

例如   6 /2  /3=1  为丑数  5 /5=1 为丑数  8/2/2/2=1为丑数  14/2=7不是  丑数


#include"iostream"
#include"windows.h"
using namespace std;

int Min(int a,int b, int c )
{
	int  min = a < b ? a : b;
	min = min < c ? min : c;
	return min;
}
//丑数 空间换时间解法  牺牲空间 换取时间
int Find1(int index) 
{
	if (index <= 0)
		return 0;//输入不合法返回0
	else
	{
		int* Ugly = new  int[index];//申请丑数的数组空间，牺牲空间 换取时间
		Ugly[0] = 1;
		int nextindex = 1;
		int* T2 = Ugly;
		int* T3 = Ugly;
		int* T5 = Ugly;
		while (nextindex < index)
		{
			while (*T2 * 2 <= Ugly[nextindex -1]) T2++;
			while (*T3 * 3 <= Ugly[nextindex -1]) T3++;
			while (*T5 * 5 <= Ugly[nextindex -1]) T5++;
			int min = Min(*T2 * 2, *T3 * 3, *T5 * 5);
			Ugly[nextindex] =  min;
			nextindex++;
		}
		int dst = Ugly[index -1];//因为数组从0开始，所以减1
		delete[] Ugly;
		return dst;
	}
}





int  Find2(int index) 
{
	if (index <= 0)
		return 0;
	else
	{
		int number = 1;
		int count = 0;
		while (count < index)
		{
			int tmp = number;
			while (number % 2 == 0) number /= 2;
			while (number % 3 == 0)number /= 3;
			while (number % 5 == 0)number /= 5;
			if (number == 1)//最后除成1了 说明就是丑数
			{
				++count;
			}
			number  = tmp + 1;
		}
		return number-1;
	}
}
int main() 
{
	//cout <<  <<endl;
	int dst1=Find1(0);

	cout << dst1 << endl;
	int dst2 = Find2(0);
	cout << dst2 << endl;
	system("pause");
	return 0;
}


//Find1 的思路： 
 // 先已知一个排好序的丑数序列 一个元素也行。
 //然后将序列中最大的（最后）元素设为M  ，在找到三个临界值（满足临界值的2 . 3   .5倍刚好是第一个大于M的数）再，选临界值中最小的//作为下一个丑数，反复更新M 和三个标杆（T2  ,T3  ,T5）;

//Find2 思路 就是挨个去比较 ，去计算，缺点是是不是丑数都被计算了