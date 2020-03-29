#if 0
#include<iostream>
#define MAX 10
using namespace std;
struct Queue
{
	int arr[MAX];
	int front;
	int rear;
	int flag;
};
bool Queue_free(Queue* Q)
{
	if (Q->front == Q->rear && Q->flag==0 )
		return true;
	return false;
}
bool Queue_max(Queue * Q)
{
	if (Q->front == Q->rear && Q->flag == 1)
		return true;
	return false;
}
void inqeue(Queue* Q,int x)
{
	if (!Queue_max(Q))
	{
		Q->rear = (Q->rear + 1) % MAX;
		Q->arr[Q->rear] = x;
		Q->flag = 1;
	}
}
int  outqueue(Queue* Q)
{
	if (!Queue_free(Q))
	{
		Q->front = (Q->front + 1) % MAX;
		if (Q->front == Q->rear)
			Q->flag = 0;
		return Q->arr[Q->front];
		
	}
}
void show(Queue *Q)
{
	for (int i = Q->front+1; i <=Q->rear; i++)
	{
		cout << Q->arr[i];
	}
}
int main(void)
{
	Queue q;
	q.front = q.rear = q.flag =0; //队列初始化
	for (int i = 0; i < 5; i++)
		inqeue(&q,i);
	for (int i = 0; i < 5; i++)
		cout << endl << outqueue(&q);

}
#endif