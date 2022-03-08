//һ����ȫ��������������������ڵ㣨��Ҷ�ӽڵ㣩��������Ϊ2*i,������Ϊ2*i+1��
//�ѣ����׽�����Ǳ��������ӽڵ�󣬾ͽ����󶥶ѣ��ʺ��������С�
//���׽ڵ�ȶ��ӽڵ�С���ͽ���С���ѣ�����ʵ�ֽ������� ��
//����һ�����飬���൱�ڸ���һ����ȫ����������������������ѵ�����
//ͨ�������ѣ����鳤��/2�պ������һ����Ҷ�ӽ�㡣Ȼ��--���Ϳ��Ա���ÿһ��Ҷ�ӽڵ㡣Ȼ��Ƚϸ��׺��������ӣ�Ȼ��Ϳ���
//�ҵ����Ľ����Ϊ����㡣
//����β���͵�һ��λ�ã��ӵ�һ����㿪ʼ���µ�����ͷ��β-1����������������Ϳ��Եõ�һ���������С�
#include<iostream>
using namespace std;
void swap(int* a, int* b)//�����õ��������� �໥�Ӽ��ķ���
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void HeapAdjust(int i, int len, int arr[])//arr�Ǵ����������飬i�Ǵ��������±ꡣlen�����鳤�ȡ�
{
	//�ȱ��浱ǰ�ӵ�
	int max = i;
	//�������Һ��ӽ��������±�
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
void HeapSort(int len, int arr[])//�󶥶�
{
	for (int i = len / 2; i >= 0; i--)
	{
		HeapAdjust(i,len,arr);
	}
	//�����Ѷ�Ԫ�غ����һ��Ԫ��
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