//题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。
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