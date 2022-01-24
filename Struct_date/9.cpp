/*题目：某个公司采用公用电话传递数据，数据是四位的整数，在传递过程中是加密的，加密规则如下：每位数字都加上5,
然后用和除以10的余数代替该数字，再将第一位和第四位交换，第二位和第三位交换。*/
#if 0;
#include<iostream>
using namespace std;
int main(void)
{
	int num = 0;
	cin >> num;
	int first, second, third, fourth;
	first = second = third = fourth = 0;
	fourth = num % 10;
	third = num / 10 % 10;
	second=num/10/10%10;
	first = num / 10 / 10 / 10 % 10;
	first=first + 5 % 10;
	second = second + 5 % 10;
	third = third + 5 % 10;
	fourth = fourth + 5 % 10;
	int temp = fourth;
	fourth = first;
	first = temp;
	int temp1 = third;
	third = second;
	second = temp1;
	cout << first << second << third << fourth;
	return 0;
}
#endif