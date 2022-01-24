#if 0;
#include<iostream>
using namespace std;
int main(void)
{
	int num;
	for (num = 1000; num < 10000; num++)
	{
		int qian = num / 1000;
		int bai = num / 10 /10% 10;
		int shi = num / 10 % 10;
		int ge = num % 10;
		if (ge == qian && bai == shi)
		{
			cout << num << endl;
		}
	}
	return 0;
}
#endif 