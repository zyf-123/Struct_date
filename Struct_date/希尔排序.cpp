#if 0;
#include<iostream>
using namespace std;
void swap(int* a, int* b)//�����õ��������� �໥�Ӽ��ķ���
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
//��Ӧ������������
void ShellSort(int num, int arr[])//����ȥģ���Ԫ����������������Ԫ�ظ����Ƚ��ٵ������Ҳ���ǲ��ϵ���СԪ�صķ�Χ
{//�����Ĳ�������
	//����Ŀǰͨ�õ��㷨 increasement/3+1

	int increasement = num;
	while (increasement > 1)
	{
		increasement = increasement / 3 + 1;

		for (int i = increasement;  i< num; i++)//ֻ��Ҫѭ��len-increasement�ξͿ���������յ�����
		{
			for (int j = i; j > 0; j--)//��������ĺ��Ĵ���
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