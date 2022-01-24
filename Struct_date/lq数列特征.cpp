#if 0;
#include<iostream>
using namespace std;
int main(void)
{
	const int N = 10000;
	int num, max, min, sum;
	sum = 0;
	cin >> num;
	int arr[N];
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	max = min = arr[0];
	for (int i = 0; i < num; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
		sum = sum + arr[i];

	}
	cout << max << endl;
	cout << min << endl;
	cout << sum << endl;
	return 0;
}
#endif