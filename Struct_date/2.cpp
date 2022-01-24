//题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
#if 0;
#include<iostream>
using namespace std;
int main(void)
{
	int num = 0;
	while (1)
	{
		double a1 = sqrt(num + 100);
		double a2 = sqrt(num + 168);
		if (a1 - int(a1) == 0 && a2 - int(a2) == 0)
		{
			break;
		}
		num++;
	}
	cout << "这个数字是" << num << endl;
}
#endif