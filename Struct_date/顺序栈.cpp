#if 0
#include<iostream>
#define M 100
using namespace std;
typedef struct stack
{
	int arr[M];
	int p;
}stacktype;//别名设置

bool judge(stack* s);//判断栈空
bool judgefree(stack* s);//判断栈满，是否会溢出
bool push(stack* s, int x);//插入栈
int pop(stack* s);//出栈

int m()
{	
	stacktype *s=new stacktype;
	s->p = -1;	//栈的初始化
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
	if (judgefree(s))//未满则操作
	{
		s->p++;
		s->arr[s->p] = x;
	}
	else
		return false;
}
int pop(stack* s)
{
	if (judge(s))//未空则操作
	{
		int x;
		x = s->arr[s->p];//取
		s->p--;//移
		return x;
	}
	else
		return -1;//此处设置可以根据情况来定
}
#endif