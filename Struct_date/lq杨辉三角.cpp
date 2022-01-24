#if 0;
#include<iostream>
using namespace std;
int main(void)
{	
	int num;
	int arr[34][34];
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		arr[i][i] = 1;
		arr[i][0] = 1;
	}
	for (int i = 2; i < num; i++)
	{
		for (int j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];

		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << arr[i][j] << " ";

		}
		cout << endl;
	}
	return 0;

}
#endif