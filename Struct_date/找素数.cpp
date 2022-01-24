#if 0;
#include <iostream>
using namespace std;
#define	M 1000
int main(void)
{
	
	int i;
	int arr[M];
	int flag = 1;
	
	arr[0] = 2;
	for (i = 3; i < M; i++)
	{
		int biaozhi = 0;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0||biaozhi==1)
			{
				break;
			}
			else
			{
				arr[flag] = i;
				flag++;
				biaozhi = 1;
			}

		}
	}
	for (int i = 0; i < flag; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}
#endif