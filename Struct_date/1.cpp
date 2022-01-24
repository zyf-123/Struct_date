#if 0;

#include <iostream>
using namespace std;

int main(void)
{
	int arr[3][3], i, j, k;
	arr[0][0] = 7;  
	arr[1][0] = 8;  
	arr[2][0] = 9;  
	for (i = 4; i < 6; i++)
		for (j = 4; j < 7; j++)
			for (k = 4; k < 7; k++)
			{
				if ((i != j && i != k && j != k) && (15 - i - arr[0][0] != 15 - j - arr[1][0] && 15 - i - arr[0][0] != 15 - k - arr[2][0] &&15 - j - arr[1][0] != 15 - k - arr[2][0]))//每个家庭第二个和第三个第三个孩子的分数都不能相等
				{
					arr[0][1] = i; arr[0][2] = 15 - 7 - i; 
					arr[1][1] = j; arr[1][2] = 15 - 8 - j;  
					arr[2][1] = k; arr[2][2] = 15 - 9 - k;
				}
			}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] == 1)   
			{
				if (i == 0)
					cout << 'Z';
				else if (i == 1)
					cout << 'W';
				else
					cout << 'L';
			}
		}

	}
	return 0;

}
#endif