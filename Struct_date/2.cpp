//��Ŀ��һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�
#if 0;
#include<iostream>
using namespace std;
int main(void)
{
	int num = 0;
	while (1)
	{
		double a1 = sqrt(num + 100);
		double a2 = sqrt(num + 168);
		if (a1 - int(a1) == 0 && a2 - int(a2) == 0)
		{
			break;
		}
		num++;
	}
	cout << "���������" << num << endl;
}
#endif