//õ�廨��
//���һ����λ����������ÿһλ����4�η�֮�ͣ����Ϊõ�廨�������磺1643 = 1 ^ 4 + 6 ^ 4 + 3 ^ 4 + 4 ^ 4���������е�õ�廨����
#if 0;
#include <iostream>
using namespace std;
int main(void)
{
	int n = 0;
	for (int i = 1000; i < 10000; i++)
	{
		int first, second, third, fourth;
		first = second = third = fourth = 0;
		fourth = i % 10;
		third = i / 10 % 10;
		second = i / 100 % 10;
		first = i /1000;
		int temp = pow(first, 4) + pow(second, 4) + pow(third, 4) + pow(fourth, 4);
		if (temp == i)
		{
			cout << temp << endl;


		}
	}
	return 0;
}
#endif