#if 0;
#include<iostream>
#include<algorithm>
using namespace std;

void swap(int* a, int* b)//不适用第三个变量 相互加减的方法
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void Bubble_Sort(int* arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}
int main(void)
{
	int num;
	int arr[210];
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];

	}

	Bubble_Sort(arr,num);
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";

	}
	return 0;
}
#endif