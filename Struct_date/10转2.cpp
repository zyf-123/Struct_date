#if 0;
#include <iostream>
using namespace std;
int main(void)
{
	int x, i, arr[255];
	cin >> x;
	i = 0;
	while (x != 0)
	{

		arr[i] = x % 2;
		i++;
		x = x / 2;
	}
	for (int j = i-1; j >= 0; j--)
	{
		cout << arr[j];
	}
	return 0;
}
#endif