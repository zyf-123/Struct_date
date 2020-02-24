#if 0
#include<iostream>
#define M 20
using namespace std;
typedef struct stack
{
	int arr[M];
	int p, q;
}stacktype;//别名设置 p和q分别代表俩个栈，位于栈的俩端
bool judge(stack* s);//判断栈满，是否会溢出
bool push(stack* s, int x,char a);//插入栈
void pop(stack* s,char a);//出栈

int main()
{
	stacktype* s = new stacktype;
	s->p = -1;
	s->q = M;	//栈的初始化
	delete s;


	return 0;
}



bool judge(stack* s)
{
	if (s->p + 1 == s->q)//左边加1等于右边的栈坐标就说明没有空间了
	{
		return (false);
	}
	else
		return (true);
}

bool push(stack* s, int x ,char a)
{

	if (judge(s))//未满则操作
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
		if (s->p != -1)//不为空才操作
		{
			int x;
			x = s->arr[s->p];//如果需要提取出来则加以改动
			s->p--;//移
		}
		else
			cout << "栈左已空";
		break;
	}
	case 'r':
	{
		if (s->q != M)//不为空才操作
		{
			//int x;
			//x = s->arr[s->q]; 如果需要提取出来则加以改动
			s->q++;//移
		}
		else
			cout << "栈右已空";
		break;
	}

	}
	
	
}
#endif