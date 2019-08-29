#define _CRT_SECURE_NO_WARNINGS
#include"iostream"
#include"stdio.h"
#include"string"
#include"stdlib.h"
#include"windows.h"
using namespace std;
class Solution
{
public:
	string Add(string num1, string num2)
	{
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		int value1 = 0, value2 = 0, next = 0;
		string addret;//设为全局变量，因为跳出循环轲能存进位
		while (end1 >= 0 || end2 >= 0)//两个数存在未遍历完继续加
		{
			if (end1 >= 0)/*判断本数是不是遍历完了*/
			{
				value1 = num1[end1--] - '0';/*左闭右开规则*/
			}
			else
			{
				value1 = 0;
			}
			if (end2 >= 0)/*判断本数是不是遍历完了*/
			{
				value2 = num2[end2--] - '0';
			}
			else
			{
				value2 = 0;
			}
			int valueret = value1 + value2 + next;
			if (valueret > 9)
			{
				next = 1;
				valueret -= 10;
			}
			else
			{
				next = 0;
			}
			addret += valueret + '0';//开始拼接
		}
		//遍历完，判断最后有无进位
		if (next == 1)
			addret += '1';
		reverse(addret.begin(), addret.end());
		return addret;
	}
};
class Solution;//前置说明
class Solution2
{
	friend class Solution;
public:
	string Mul(string num1, string num2)
	{
		int end1 = num1.size() - 1;/*操作数长度*/
		int end2 = num2.size() - 1;
		int value1 = 0, value2 = 0, next = 0;/*记录各位数字*/
		int valueret;
		string  tmp1, tmp2;	string addret;
		string Mulret;
 		for (int i = end1; i >= 0; i--)
		{
			value1 = num1[i] - '0';//获取各位数字
			for (int j = end2; j >= 0; j--)
			{
				value2 = num2[j] - '0';
				//cout << "value2:" << value2<<endl << "value1:" << value1 << endl;
				valueret = value1 * value2 + next;
				//cout << "valueret:" << valueret << endl;
				if (valueret > 9)
				{
					next = valueret / 10;
					valueret %= 10;
				}
				else								/*记录进位情况*/
				{
					next = 0;
				}
				addret += valueret + '0';
				//cout <<"里层遍历"<< addret << endl;
			}
			reverse(addret.begin(), addret.end());
			//cout <<"里层翻转" <<addret << endl;

			if (next != 0)
			{
				addret.insert(addret.begin(), next + '0');
			}
			if (i != end1)
			{
				addret.append(end1 - i, '0');
			}
			//cout << "外层换行补0" <<':'<<addret<< endl;
			tmp1 = addret;
			tmp2=s1.Add(tmp2,tmp1);
			//tmp1.clear();
			addret.clear();
			//	cout<<"临时tmp1:"<<tmp1<<endl;
		}
		addret = tmp2;
		return addret;
	}
	Solution s1;
};
void Test2()
{
	Solution s1;
	string a, b;
	while (cin >> a >> b)
	{
		string tmp = s1.Add(a, b);
		tmp.c_str();
		//	char * s2 = (char*)  (s1.Add(a, b)) .c_str();
		cout << tmp << endl;
	}
}
void Test3()
{
	Solution2 s;
	string a, b;
	while (cin >> a >> b)
	{
		string c = s.Mul(a, b);
		//	 char *d= (char*)c.c_str();
		cout << c << endl;
		//	printf("%s\n",c);
	}
}
int main()
{
	//Test();
	cout << "请输入要操作的串数字" << endl;
	//Test2();
	Test3();
	system("pause");
	return 0;
}

//乘法的总结 ，除过第一次外每出一次内层循环，所得结果补0，切记内层结果每次清零。调用友元类进行友元函数add的调用。