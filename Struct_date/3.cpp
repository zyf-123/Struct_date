//题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
#if 0;
#include <iostream>
using namespace std;
int main(void)
{
	int num;
	cin >> num;
	int i ;
	for (i = 2; i <= num; i++)
	{
		if (num % i == 0)
		{
			if (i == num)
			{
			cout<<i;
				break;
			}
			cout << i<<"*";
			num = num / i;
			i--;
		}
		

	}


}
#endif