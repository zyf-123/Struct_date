#if 0;
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(void)
{
	char arr[8] = {0};
	cin >> arr;
	long long sum = 0;
	int len = strlen(arr) - 1;
	for (int i = len; i >=0; i--)
	{
		if (arr[i] == 'F')
		{
			sum = sum + 15 * pow(16, len-i);
		}
		else if (arr[i] == 'E')
		{
			sum = sum + 14* pow(16, len - i);
		}
		else if (arr[i] == 'D')
		{
			sum = sum + 13 * pow(16, len - i);
		}
		else if (arr[i] == 'C')
		{
			sum = sum + 12 * pow(16, len - i);
		}
		else if (arr[i] == 'B')
		{
			sum = sum + 11 * pow(16, len - i);
		}
		else if (arr[i] == 'A')
		{
			sum = sum + 10 * pow(16, len - i);
		}
		else
		{
			sum = sum + (arr[i]-48) * pow(16, len - i);
		}
		
	}
	cout << sum;
	return 0;
}
#endif