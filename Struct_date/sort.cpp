#if 0;
#include<iostream>
#include<algorithm>
using namespace std;
//sort������������һ����ʼ��һ����β������һ����������ݣ�����˵�Ƿ�������������������õ����򷽷�sort(1, 10, greater<int>());<int>�ڲ�Ϊһ�����ͱ�̵ı�����

bool cmp(int x,int y)//�Ƚ�x,y��ֵ���ҷ���bool���͵ı���
{
	return x > y;
}
bool mod3(int x, int y)
{
	if (x % 3 != y % 3)
	{
		return x % 3 > y % 3;
	}
	else
	{
		return x > y;
	}
}
struct Student
{
	string name;
	int score[4];
};
bool name(Student x, Student y)//�����ֵ�����
{
	return x.name > y.name;
}
bool name(Student x, Student y)//���ճɼ���������
{
	if (x.score[0] != y.score[0])
		return x.score[0] > y.score[0];
	if (x.score[1] != y.score[1])
		return x.score[1] > y.score[1];
	if (x.score[2] != y.score[2])
		return x.score[2] > y.score[2];
	return x.score[3] > y.score[3];
}
int num[105];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	sort(num, num + N, mod3);
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1)
		{
			cout << num[i] << " ";

		}
		else
		{
			cout << num[i] << endl;
		}
	}

	
	return 0;
}
#endif 