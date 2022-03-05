#if 0;
#include<iostream>
using namespace std;
void swap(int* a, int* b)//不适用第三个变量 相互加减的方法
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}//适合小量的数据进行排序
void InsertSort(int num, int arr[])//在元素序列基本有序的情况下和元素个数比较少的情况下排序速度比较快
{

	for (int i = 0; i < num; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
			
		}
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
	InsertSort(num, arr);
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";

	}
	return 0;

}
#endif