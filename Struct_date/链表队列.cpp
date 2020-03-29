#if 0
#include<iostream>
using namespace std;
typedef struct Q
{
	int data;
	Q* next;
};
struct point
{
	Q* front;
	Q* rear;
};

point* init(void)
{
	Q *head = new Q;
	head->next = NULL;//头节点
	point* x=new point;
	x->front = head;//front指向头节点
	if (x->front != NULL)
	{
		x->rear = x->front;
	}
	return x;
}
void in(point* x, int y)
{
	Q* New = new Q;
	if (New != NULL)
	{
		New->data = y;//赋值
		New->next = NULL;//尾部置空
		x->rear->next = New;//链接new到队列上
		x->rear = New;//移动rear
	}
}

int out(point* x)
{
	if (x->front != x->rear)
	{
		Q* p = x->front->next;
		x->front->next = p->next;
		if (x->rear == p)//假设队列只有一个元素的时候，移动rear指向头指针
		{
			x->rear = x->front;
		}
		int y = p->data;
		delete p;
		return y;
	}
	return 0;
}
int main(void)
{
	point* x =init();
	for( int i=1;i<=10;i++)

	in(x,i);
	
	while(cout << out(x));//修改了这个
}
#endif