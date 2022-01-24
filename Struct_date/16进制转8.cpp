#if 0;
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
long long int zhuan(char arr[])
{
	long long sum = 0;
	int len = strlen(arr) - 1;
	for (int i = len; i >= 0; i--)
	{
		if (arr[i] == 'F')
		{
			sum = sum + 15 * pow(16, len - i);
		}
		else if (arr[i] == 'E')
		{
			sum = sum + 14 * pow(16, len - i);
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
			sum = sum + (arr[i] - 48) * pow(16, len - i);
		}

	}
	return sum;
}
long long  zhuan8(long long num)
{
	long long jieguo = 0;
	int i = 0;
	while (1)
	{
		jieguo = jieguo+num % 8 * pow(10, i);
		i++;
		num = num / 8;
		if (num == 0)
			break;
	}
	return jieguo;
}
int main(void)
{
	int n;
	char arr[10][8];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		int num;
		num=zhuan(arr[i]);
		
		cout << zhuan8(num) << endl;
	}
	

	return 0;
}
#endif