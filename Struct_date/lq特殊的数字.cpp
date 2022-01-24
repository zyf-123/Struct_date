#if 0;
#include <iostream>
#include<cmath>
using namespace std;
int main(void)
{
	for (int i = 100; i< 1000; i++)
	{
		int bai = i / 10 / 10 % 10;
		int shi = i / 10 % 10;
		int ge = i % 10;
		int sum = pow(ge, 3) + pow(shi, 3) + pow(bai, 3);
		if (sum == i)
		{
			cout << sum << endl;
		}

	}
	return 0;

}
#endif