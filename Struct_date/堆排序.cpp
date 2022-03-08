//一个完全二叉树，在数组中任意节点（非叶子节点）的左子树为2*i,右子树为2*i+1；
//堆：父亲结点总是比俩个儿子节点大，就叫做大顶堆，适合升序排列。
//父亲节点比儿子节点小，就叫做小顶堆，可以实现降序排列 。
//给了一个数组，就相当于给了一个完全二叉树，但是他并不满足堆的条件
//通过调整堆，数组长度/2刚好是最后一个非叶子结点。然后--，就可以遍历每一个叶子节点。然后比较父亲和俩个孩子，然后就可以
//找到最大的结点作为父结点。
//交换尾部和第一个位置，从第一个结点开始往下调整。头和尾-1继续交换。遍历后就可以得到一个有序序列。
#include<iostream>
using namespace std;
void swap(int* a, int* b)//不适用第三个变量 相互加减的方法
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void HeapAdjust(int i, int len, int arr[])//arr是待调整的数组，i是待调整的下标。len是数组长度。
{
	//先保存当前接单
	int max = i;
	//保存左右孩子结点数组的下标
	int lchild = i * 2+1;
	int rchild = i * 2 + 2;
	if (lchild < len && arr[lchild]>arr[max])
	{
		max = lchild;
	}
	if (rchild<len && arr[rchild]>arr[max])
	{
		max = rchild;
	}
	if (max != i)
	{
		swap(arr[max], arr[i]);
		HeapAdjust(max,len,arr);
	}
}
void HeapSort(int len, int arr[])//大顶堆
{
	for (int i = len / 2; i >= 0; i--)
	{
		HeapAdjust(i,len,arr);
	}
	//交换堆顶元素和最后一个元素
	for (int i = len - 1; i >= 0; i--)
	{
		swap(arr[i], arr[0]);
		HeapAdjust(0, i, arr);
	}

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
	HeapSort(len, arr);
	for (int i = 0; i < len; i++)
	{
		cout<<arr[i];
	}
	return 0;
}