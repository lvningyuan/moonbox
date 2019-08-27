#include"iostream"
#include"string"
#include"windows.h"
#include"stack"
#include"assert.h"
using namespace std;
class A 
{
public : 
	void ps(int n)//个数
	{
		cout << "请输入待入栈元素" << endl;
		while (n--)
		{
			int tmp;
			cin >> tmp;
			_elem.push(tmp);//其实就是调用库函数push  先数据入栈
			if (_min.empty() || _min.top() >tmp )

				_min.push(tmp);//进最小栈
		}
	}
	void pp(int x)
	{
	assert(x>0);
		while (x--)
		{
			if (_elem.top() == _min.top())
				_min.pop();

			_elem.pop();
		}
		cout << _min.top() << endl;
	}
private :
	std::stack<int> _elem;//数据栈
	std::stack<int> _min;//当前最小元素栈
};
int main() {


	A a;
	//cout<<"请输入元素个数"<<endl;
	a.ps(4);
	a.pp(2);
	//int len = sizeof(string);
	//cout << len << endl;
	system("pause");
	return 0;
}