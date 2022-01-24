//题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
#if 0;
#include <iostream>
using namespace std;
int main(void)
{
	double num = 100;
	double sum = num;
	for (int i = 0; i < 10; i++)
	{
		
		num = num / 2;
		sum = sum + num*2;
	}
	cout << sum << endl;
	cout << num;
	return 0;

}
#endif