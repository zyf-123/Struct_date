#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{
	int x;
	int sum=0, i = 0,temp=0;
	cin >> x;
	while(x!=0)
	{
		temp = x % 10;
		x = x / 10;
		sum = sum + pow(2, i) * temp;
		i++;
	}
	cout << sum;
	return 0;
}