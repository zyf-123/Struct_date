#if 0
#include<iostream>
#define M 100
using namespace std;
typedef struct stack
{
	char arr[M];
	int p;
}stacktype;//��������

bool judge(stack* s);//�ж�ջ��
bool judgefree(stack* s);//�ж�ջ�����Ƿ�����
bool push(stack* s, char x);//����ջ
char pop(stack* s);//��ջ

int main()
{
	stacktype* s = new stacktype;
	s->p = -1;	//ջ�ĳ�ʼ��
	string arr = "{()[]}";
	int flag = 0;
	for (auto ch:arr)//����c++11�ķ�Χforѭ��
	{
		if (ch == '[' || ch == '{' || ch == '(')
		{
			push(s, ch);
		}
		else if (ch == ']' || ch == '}' || ch == ')')
		{
			char a = pop(s);
			if ((a == '{' && ch == '}') || (a == '(' && ch == ')') || (a == '[' && ch == ']'))//ƥ����Ϊ1
				flag = 1;
			else//��ƥ��Ļ�˵���Լ����ִ���û��Ҫִ����ȥ��ֱ���˳�ѭ��
			{
				flag = 0;
				break;
			}
		}
	}
	//if (judge(s))
	//	flag = 0;
	cout << (flag ? 'Y' : 'N');
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
	if (s->p == M - 1)
	{
		return (false);
	}
	else
		return (true);
}

bool push(stack* s, char x)
{
	if (judgefree(s))//δ�������
	{
		s->p++;
		s->arr[s->p] = x;
		return true;
	}
	else
		return false;
}

char pop(stack* s)
{
	if (judge(s))//δ�������
	{
		char x;
		x = s->arr[s->p];//ȡ
		s->p--;//��
		return x;
	}
	else
		return 'n';//�˴����ÿ��Ը����������
}
#endif