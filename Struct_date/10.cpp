//玫瑰花数
//如果一个四位数等于它的每一位数的4次方之和，则称为玫瑰花数。例如：1643 = 1 ^ 4 + 6 ^ 4 + 3 ^ 4 + 4 ^ 4编程输出所有的玫瑰花数。
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