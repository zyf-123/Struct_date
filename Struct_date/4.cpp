//题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
#if 0;
#include<iostream>
using namespace std;
int main(void)
{
	int a;
	int num;
	int sum;
	int temp;
	sum=num = a =temp= 0;
	cin >> a;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		temp = a + temp;
		sum = sum + temp;
		a=a * 10;
	}
	cout << sum;
	return 0;
}
#endif