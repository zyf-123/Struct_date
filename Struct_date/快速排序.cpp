#if 0;
#include<iostream>
using namespace std;

void QuickSort(int start, int end, int arr[])
{
	int i = start;
	int j = end;
	int temp = arr[start];//设置基准参数
	if (i >= j)//递归的结束条件
	{
		return;
	}
	while (i < j)
	{
		//从右边向左去找比基准数小的元素
		while (i < j && arr[j] >= temp)
		{
			j--;
		}
		//填坑
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		//从左边向右边找比基准数更大的数字
		while (i < j && arr[i] < temp)
		{
			i++;
		}
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	//把基准数放到i==j的位置
	arr[i] = temp;
	//对左边部分进行快排
	QuickSort(start, i - 1,arr);
	//右半部分
	QuickSort(i + 1, end, arr);
}
int main(void)
{
	const int MAX = 1024;
	int arr[MAX];
	int len;
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}
	QuickSort(0, len - 1, arr);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";

	}

	return 0;
}
#endif