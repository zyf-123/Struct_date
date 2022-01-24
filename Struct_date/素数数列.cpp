#if 0;#include<iostream>
#define	M 30000
using namespace std;
bool issushu(int x)
{
	int i;
	for (i = 2; i < x; i++)
	{


		if (x % i == 0 && x != i)
		{
			return 0;
		}


	}
	if (i == x)
		return 1;

}

int main(void)
{
	int i, j, k;
	int an = 0;
	int flag = 0;
	for (i = 2; i < M; i++)
	{

		if (issushu(i)&&!flag)
		{
			for ( j = 1; j < 1000; j++)
			{
				for (k = 1; k <= 9; k++)
				{
					an = i + k * j;
					if (issushu(an))
					{
						continue;
					}
					else
						break;
				}
				if (k ==10 && (issushu(an)))
				{
					cout << j << endl;
					flag = 1;
					break;
					
				}
				else
					continue;
			}
			
		}
		if (flag)
			break;
	}
	return 0;
	}
#endif