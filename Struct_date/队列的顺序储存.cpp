#if 0;
#include <cstddef>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
#define MAX_SIZE 1024
typedef struct SEQQUEUE
{
	void* data[MAX_SIZE];
	int size;
}Seqqueue;

//初始化
Seqqueue* Init_seqqueue();
//入队
void Push_Seqqueue(Seqqueue* queue, void* data);
//返回队头元素
void* Front_Seqqueue(Seqqueue* queue);
//出队操作
void Pop_Seqqueue(Seqqueue* queue);
//返回队尾元素
void* Back_Seqqueue(Seqqueue* queue);
//返回大小
int Size_Seqqueue(Seqqueue* queue);
//清空队列
void clear_Seqqueue(Seqqueue* queue);
//销毁队列
void Free_Seqqueue(Seqqueue* queue);

//初始化
Seqqueue* Init_seqqueue()
{
	Seqqueue* queue = new Seqqueue;
	queue->size = 0;
	queue->data[MAX_SIZE] = { nullptr };
	return queue;
}
//入队
void Push_Seqqueue(Seqqueue* queue, void* data)
{
	//数组的左边当作对头
	if (queue == nullptr || data == nullptr || queue->size == MAX_SIZE)
	{
		return;
	}
	queue->data[queue->size] = data;
	queue->size++;
}
//返回队头元素
void* Front_Seqqueue(Seqqueue* queue)
{
	if (queue == nullptr || queue->size == 0)
	{
		return nullptr;
	}
	return queue->data[0];
}
//出队操作
void Pop_Seqqueue(Seqqueue* queue)
{
	if (queue == nullptr || queue->size == 0)
	{
		return;
	}
	//将后续的元素依次向前移动
	for (int i = 0; i < queue->size; i++)
	{
		queue->data[i] = queue->data[i + 1];
	}
	queue->size--;
}
//返回队尾元素
void* Back_Seqqueue(Seqqueue* queue)
{
	if (queue == nullptr || queue->size == 0)
	{
		return nullptr;
	}
	return queue->data[queue->size - 1];
}
//返回大小
int Size_Seqqueue(Seqqueue* queue)
{
	if (queue == nullptr)
	{
		return -1;
	}
	return queue->size;
}
//清空队列
void clear_Seqqueue(Seqqueue* queue)
{
	if (queue == nullptr)
	{
		return;
	}
	queue->size = 0;
}
//销毁队列
void Free_Seqqueue(Seqqueue* queue)
{
	if (queue == nullptr)
	{
		return;
	}
	delete queue;
}
typedef struct Person
{
	char name[64];
};
int main(void)
{
	//创建队列
	Seqqueue* queue = Init_seqqueue();
	//创建数据
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");
	Push_Seqqueue(queue, &p1);
	Push_Seqqueue(queue, &p2);
	Push_Seqqueue(queue, &p3);
	Push_Seqqueue(queue, &p4);
	Push_Seqqueue(queue, &p5);
	Person* prear = (Person*)Back_Seqqueue(queue);
	cout << "目前队尾的元素是" << prear->name << endl;
	while (queue->size > 0)
	{
		//访问栈顶元素
		Person* per = (Person*)Front_Seqqueue(queue);
		cout << per->name << endl;
		//弹出元素
		Pop_Seqqueue(queue);
	}

	return 0;
}
#endif