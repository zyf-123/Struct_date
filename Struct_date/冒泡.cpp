#if 0;
#include<iostream>
#include<algorithm>
using namespace std;

void swap(int* a, int* b)//�����õ��������� �໥�Ӽ��ķ���
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void Bubble_Sort(int* arr, int num)
{
	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < num-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
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

	Bubble_Sort(arr, num);
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";

	}
	return 0;
}
#endif