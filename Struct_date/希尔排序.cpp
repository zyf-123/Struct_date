#if 0;
#include<iostream>
using namespace std;
void swap(int* a, int* b)//不适用第三个变量 相互加减的方法
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
//适应大量数据排序
void ShellSort(int num, int arr[])//尽力去模拟出元素序列有序的情况和元素个数比较少的情况，也就是不断的缩小元素的范围
{//分组后的插入排序
	//增量目前通用的算法 increasement/3+1

	int increasement = num;
	while (increasement > 1)
	{
		increasement = increasement / 3 + 1;

		for (int i = increasement;  i< num; i++)//只需要循环len-increasement次就可以完成最终的排序
		{
			for (int j = i; j > 0; j--)//插入排序的核心代码
			{
				if (arr[j] < arr[j - 1])
					swap(arr[j], arr[j - 1]);
				else
					break;

			}
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
	ShellSort(num, arr);
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";

	}
	return 0;

}
#endif