#if 0
#include<iostream>
#define M 100
using namespace std;
typedef struct stack
{
	int arr[M];
	int p;
}stacktype;//��������

bool judge(stack* s);//�ж�ջ��
bool judgefree(stack* s);//�ж�ջ�����Ƿ�����
bool push(stack* s, int x);//����ջ
int pop(stack* s);//��ջ

int m()
{	
	stacktype *s=new stacktype;
	s->p = -1;	//ջ�ĳ�ʼ��
	delete s;
	return 0;
}

bool judge(stack* s)
{
	if (s->p == -1)
	{
		return (false);
	}
	else
		return (true);
}

bool judgefree(stack* s)
{
	if (s->p==M-1)
	{
		return (false);
	}
	else
		return (true);
}

bool push(stack* s, int x)
{
	if (judgefree(s))//δ�������
	{
		s->p++;
		s->arr[s->p] = x;
	}
	else
		return false;
}
int pop(stack* s)
{
	if (judge(s))//δ�������
	{
		int x;
		x = s->arr[s->p];//ȡ
		s->p--;//��
		return x;
	}
	else
		return -1;//�˴����ÿ��Ը����������
}
#endif