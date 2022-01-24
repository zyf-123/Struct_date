#if 0;
#include<iostream>
using namespace std;
int main(void)
{
	double arr[30][30];
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < 30; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				arr[i][j] += arr[i - 1][j] / 2;
			}
			else if (j == i)
			{
				arr[i][j] += arr[i - 1][j - 1] / 2;
			}
			else
			{
				arr[i][j] = arr[i - 1][j - 1] / 2 + arr[i - 1][j] / 2 + arr[i][j];
			}

		}
	}
	double max = arr[29][0];
	double min = arr[29][0];
	for (int j = 0; j < 30; j++)
	{
		cout << arr[29][j] << " ";
		if (max < arr[29][j])
		{
			max = arr[29][j];
		}
		if (min > arr[29][j])
		{
			min = arr[29][j];
		}
	}
	double zhongjian = 2086458231 / min;
	cout << endl;
	double jieguo = zhongjian * max;
	cout << jieguo;
	cout << endl;
	return 0;
}
#endif