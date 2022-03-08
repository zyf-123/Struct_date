#if 0;
#include<iostream>
using namespace std;

void QuickSort(int start, int end, int arr[])
{
	int i = start;
	int j = end;
	int temp = arr[start];//���û�׼����
	if (i >= j)//�ݹ�Ľ�������
	{
		return;
	}
	while (i < j)
	{
		//���ұ�����ȥ�ұȻ�׼��С��Ԫ��
		while (i < j && arr[j] >= temp)
		{
			j--;
		}
		//���
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		//��������ұ��ұȻ�׼�����������
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
	//�ѻ�׼���ŵ�i==j��λ��
	arr[i] = temp;
	//����߲��ֽ��п���
	QuickSort(start, i - 1,arr);
	//�Ұ벿��
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