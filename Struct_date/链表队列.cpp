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
	head->next = NULL;//ͷ�ڵ�
	point* x=new point;
	x->front = head;//frontָ��ͷ�ڵ�
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
		New->data = y;//��ֵ
		New->next = NULL;//β���ÿ�
		x->rear->next = New;//����new��������
		x->rear = New;//�ƶ�rear
	}
}

int out(point* x)
{
	if (x->front != x->rear)
	{
		Q* p = x->front->next;
		x->front->next = p->next;
		if (x->rear == p)//�������ֻ��һ��Ԫ�ص�ʱ���ƶ�rearָ��ͷָ��
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
	
	while(cout << out(x));//�޸������
}
#endif