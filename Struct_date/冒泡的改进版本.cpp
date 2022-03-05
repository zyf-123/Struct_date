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
	int flag = 0;//标识没有排序好
	int number = 0;
	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < num - i; j++)
		{
			flag = 0;
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 1;
				
			}
			number++;
			if (flag == 0)
			{
				cout << number << endl;
				return;

			}
		}
	}
	cout << number << endl;
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

	Bubble_Sort(arr, num);
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";

	}
	return 0;
}
#endif