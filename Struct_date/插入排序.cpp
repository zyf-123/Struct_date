#if 0;
#include<iostream>
using namespace std;
void swap(int* a, int* b)//�����õ��������� �໥�Ӽ��ķ���
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}//�ʺ�С�������ݽ�������
void InsertSort(int num, int arr[])//��Ԫ�����л������������º�Ԫ�ظ����Ƚ��ٵ�����������ٶȱȽϿ�
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