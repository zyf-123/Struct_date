#if 0;
//��һ���������кϲ���һ���������� ��һ�ַ��β���
// �ֽ�ɵ������ݣ�Ȼ��ͣ��ȥ���ϳ�һ������������
#include<iostream>
using namespace std;
//�ϲ����� ��С����
void Merge(int arr[], int start, int end, int  mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	//��ʶ�����ռ����ж���Ԫ��
	int length = 0;
	//�ϲ�������������
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
	//i���������ʣ��Ԫ��
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	//j������ʣ��Ԫ��
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		j_start++;
		length++;
	}
	//�����ռ�����ݸ��ǵ�ԭ���Ŀռ�
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}
//�鲢����
void MergeSort(int arr[],int start,int end,int * temp)
{
	if (start >= end)
		return;
	//ȷ��һ���м��
	int mid = (start + end) / 2;
	//����
	//����
	MergeSort(arr, start, mid, temp);
	//�Ұ��
	MergeSort(arr, mid+1, end, temp);
	//�ϲ�
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