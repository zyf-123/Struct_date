#if 0
#include<iostream>
#define M 100
using namespace std;
typedef struct stack
{
	char arr[M];
	int p;
}stacktype;//别名设置

bool judge(stack* s);//判断栈空
bool judgefree(stack* s);//判断栈满，是否会溢出
bool push(stack* s, char x);//插入栈
char pop(stack* s);//出栈

int main()
{
	stacktype* s = new stacktype;
	s->p = -1;	//栈的初始化
	string arr = "{()[]}";
	int flag = 0;
	for (auto ch:arr)//基于c++11的范围for循环
	{
		if (ch == '[' || ch == '{' || ch == '(')
		{
			push(s, ch);
		}
		else if (ch == ']' || ch == '}' || ch == ')')
		{
			char a = pop(s);
			if ((a == '{' && ch == '}') || (a == '(' && ch == ')') || (a == '[' && ch == ']'))//匹配则为1
				flag = 1;
			else//不匹配的话说明以及出现错误，没必要执行下去，直接退出循环
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
	if (judgefree(s))//未满则操作
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
	if (judge(s))//未空则操作
	{
		char x;
		x = s->arr[s->p];//取
		s->p--;//移
		return x;
	}
	else
		return 'n';//此处设置可以根据情况来定
}
#endif