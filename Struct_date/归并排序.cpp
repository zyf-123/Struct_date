#if 0;
//将一个有序序列合并成一个有序序列 是一种分治策略
// 分解成单个数据，然后不停的去整合成一个完整的数组
#include<iostream>
using namespace std;
//合并函数 从小到大
void Merge(int arr[], int start, int end, int  mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	//标识辅助空间内有多少元素
	int length = 0;
	//合并俩个有序序列
	while (i_start <= i_end && j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[length] = arr[i_start];
			length++;
			i_start++;
		}
		else
		{
			temp[length] = arr[j_start];
			length++;
			j_start++;
		}
	}
	//i这个序列有剩余元素
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	//j序列有剩余元素
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		j_start++;
		length++;
	}
	//辅助空间的数据覆盖到原来的空间
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}
//归并排序
void MergeSort(int arr[],int start,int end,int * temp)
{
	if (start >= end)
		return;
	//确定一个中间点
	int mid = (start + end) / 2;
	//分组
	//左半边
	MergeSort(arr, start, mid, temp);
	//右半边
	MergeSort(arr, mid+1, end, temp);
	//合并
	Merge(arr, start, end, mid,temp);
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
	int* temp = new int[1024];
	MergeSort(arr, 0, len - 1, temp);
	for (int j = 0; j < len; j++)
	{
		cout << arr[j] << " ";
	}
	delete temp;
	return 0;
}
#endif