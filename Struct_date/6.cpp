//��Ŀ������ƹ����ӽ��б������������ˡ��׶�Ϊa, b, c���ˣ��Ҷ�Ϊx, y, z���ˡ��ѳ�ǩ���������������������Ա����������������a˵������x�ȣ�c˵������x, z�ȣ��������ҳ��������ֵ�������
#if 0;
#include <iostream>
using namespace std;
int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int  j = 0; j < 3; j++)
		{
			if (i != j)
			{
				for (int  k = 0; k < 3; k++)
				{
					if (k != i && k != j)
					{
						if (i != 0 && k != 0 && k != 2)
						{
							cout << "a��" << i << "b" << j << "c" << k;
						}
					}
				}
			}
		}
	}
	return 0;
}
#endif