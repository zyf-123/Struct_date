//��Ŀ����һ�������У�2/1��3/2��5/3��8/5��13/8��21/13...���������е�ǰ20��֮�͡�
#if 0;
#include<iostream>
using namespace std;
int main(void)
{
	double i = 2;
	double j = 1;
	double sum = 0;
	for (int k = 0; k < 20; k++)
	{
		double temp = i / j;
		sum = sum + temp;
		//double t = j;
		//j = i + j;
		//i = t;
		i = i + j;
		j = i-j;

	}
	cout << sum;
}
#endif