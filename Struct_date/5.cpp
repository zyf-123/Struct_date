//��Ŀ��һ���100�׸߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룻�����£������ڵ�10�����ʱ�������������ף���10�η�����ߣ�
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