#if 0
#include<iostream>
#define M 20
using namespace std;
typedef struct stack
{
	int arr[M];
	int p, q;
}stacktype;//�������� p��q�ֱ��������ջ��λ��ջ������
bool judge(stack* s);//�ж�ջ�����Ƿ�����
bool push(stack* s, int x,char a);//����ջ
void pop(stack* s,char a);//��ջ

int main()
{
	stacktype* s = new stacktype;
	s->p = -1;
	s->q = M;	//ջ�ĳ�ʼ��
	delete s;


	return 0;
}



bool judge(stack* s)
{
	if (s->p + 1 == s->q)//��߼�1�����ұߵ�ջ�����˵��û�пռ���
	{
		return (false);
	}
	else
		return (true);
}

bool push(stack* s, int x ,char a)
{

	if (judge(s))//δ�������
	{
		switch (a)
		{
		case 'l':
		{
			s->p++;
			s->arr[s->p] = x;
			break;
		};
		case 'r':
		{
			s->q--;
			s->arr[s->q] = x;
			break;
		}
		default: cout << "error";
		}
	}
	else
		return false;
}

void pop(stack* s,char a)
{
	switch(a)
	{
	case 'l':
	{
		if (s->p != -1)//��Ϊ�ղŲ���
		{
			int x;
			x = s->arr[s->p];//�����Ҫ��ȡ��������ԸĶ�
			s->p--;//��
		}
		else
			cout << "ջ���ѿ�";
		break;
	}
	case 'r':
	{
		if (s->q != M)//��Ϊ�ղŲ���
		{
			//int x;
			//x = s->arr[s->q]; �����Ҫ��ȡ��������ԸĶ�
			s->q++;//��
		}
		else
			cout << "ջ���ѿ�";
		break;
	}

	}
	
	
}
#endif