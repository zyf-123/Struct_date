#if 0;
#include<iostream>
using namespace std;
int main(void)
{
	const int N = 1000;
	int num, find;
	cin >> num;
	int arr[N];
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	cin >> find;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] == find)
		{
			cout << i+1;
			return 0;//Ҳ��������һ��flag���������������ж�
		}
		
	}
	cout <<  - 1;
	

}
#endif