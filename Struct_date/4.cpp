//��Ŀ����s=a+aa+aaa+aaaa+aa...a��ֵ������a��һ�����֡�����2+22+222+2222+22222(��ʱ����5�������)������������м��̿��ơ�
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