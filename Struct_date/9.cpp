/*��Ŀ��ĳ����˾���ù��õ绰�������ݣ���������λ���������ڴ��ݹ������Ǽ��ܵģ����ܹ������£�ÿλ���ֶ�����5,
Ȼ���úͳ���10��������������֣��ٽ���һλ�͵���λ�������ڶ�λ�͵���λ������*/
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