#if 0;
#include <iostream>
using namespace std;
int main(void)
{
	int num;
	cin >> num;
	for (int i = 10000; i < 1000000; i++)
	{
		int shiwan = i / 100000;
		int wan = i / 10000 % 10;
		int qian = i / 1000 % 10;
		int bai = i / 10 / 10 % 10;
		int shi = i / 10 % 10;
		int ge = i % 10;
		int sum = shiwan + wan + qian + bai + shi + ge;
		if (shiwan == 0)
		{
			if (sum == num&&wan==ge&&qian==shi)
			{
				cout << i << endl;

			}
		}
		else
		{
			if (sum == num && shiwan == ge && wan== shi&&bai==qian)
			{
				cout << i << endl;

			}
		}

	}
	return 0;

}
#endif