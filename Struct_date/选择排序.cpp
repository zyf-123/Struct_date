#if 0;
#include<iostream>
using namespace std;
void swap(int* a, int* b)//不适用第三个变量 相互加减的方法
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void SelectSort(int num,int arr[])
{
	
	for (int i = 0; i < num; i++)
	{
		int min = i;
		for (int j = i + 1; j < num; j++)
		{
			if (arr[j] < arr[min])
				min = j;

		}
		swap(arr[min], arr[i]);
	}
}
int main(void)
{
	int num = 0;
	int arr[10];
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	SelectSort(num, arr);
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";

	}
	return 0;

}
#endif