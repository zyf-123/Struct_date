//��Ŀ����һ���������ֽ������������磺����90,��ӡ��90=2*3*3*5��
#if 0;
#include <iostream>
using namespace std;
int main(void)
{
	int num;
	cin >> num;
	int i ;
	for (i = 2; i <= num; i++)
	{
		if (num % i == 0)
		{
			if (i == num)
			{
			cout<<i;
				break;
			}
			cout << i<<"*";
			num = num / i;
			i--;
		}
		

	}


}
#endif