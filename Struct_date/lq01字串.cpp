#if 0;
#include<iostream>
using namespace std;

int main(void)
{
	//一种新的转换二进制的位数的方式 数字/权值%权就可以看是0还是1
	int i;
	for (i = 0; i < 32; ++i)
		cout<<i / 16 % 2<<i / 8 % 2<<i / 4 % 2<<i / 2 % 2<<i % 2<<endl;
	return 0;
}
#endif