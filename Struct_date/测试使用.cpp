#if 0;
#include<iostream>
using namespace std;
void print(int* arr)
{
	for (int i = 0; i < 10; i++)
	{
		cout<<arr[i];
	}
}
int main(void)
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
	}
	print(a);

	return 0;
}
#endif 