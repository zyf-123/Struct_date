#if 0;
#include<iostream>
using namespace std;

int main(void)
{
	//һ���µ�ת�������Ƶ�λ���ķ�ʽ ����/Ȩֵ%Ȩ�Ϳ��Կ���0����1
	int i;
	for (i = 0; i < 32; ++i)
		cout<<i / 16 % 2<<i / 8 % 2<<i / 4 % 2<<i / 2 % 2<<i % 2<<endl;
	return 0;
}
#endif