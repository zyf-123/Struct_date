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

//��ʼ��
Seqqueue* Init_seqqueue();
//���
void Push_Seqqueue(Seqqueue* queue, void* data);
//���ض�ͷԪ��
void* Front_Seqqueue(Seqqueue* queue);
//���Ӳ���
void Pop_Seqqueue(Seqqueue* queue);
//���ض�βԪ��
void* Back_Seqqueue(Seqqueue* queue);
//���ش�С
int Size_Seqqueue(Seqqueue* queue);
//��ն���
void clear_Seqqueue(Seqqueue* queue);
//���ٶ���
void Free_Seqqueue(Seqqueue* queue);

//��ʼ��
Seqqueue* Init_seqqueue()
{
	Seqqueue* queue = new Seqqueue;
	queue->size = 0;
	queue->data[MAX_SIZE] = { nullptr };
	return queue;
}
//���
void Push_Seqqueue(Seqqueue* queue, void* data)
{
	//�������ߵ�����ͷ
	if (queue == nullptr || data == nullptr || queue->size == MAX_SIZE)
	{
		return;
	}
	queue->data[queue->size] = data;
	queue->size++;
}
//���ض�ͷԪ��
void* Front_Seqqueue(Seqqueue* queue)
{
	if (queue == nullptr || queue->size == 0)
	{
		return nullptr;
	}
	return queue->data[0];
}
//���Ӳ���
void Pop_Seqqueue(Seqqueue* queue)
{
	if (queue == nullptr || queue->size == 0)
	{
		return;
	}
	//��������Ԫ��������ǰ�ƶ�
	for (int i = 0; i < queue->size; i++)
	{
		queue->data[i] = queue->data[i + 1];
	}
	queue->size--;
}
//���ض�βԪ��
void* Back_Seqqueue(Seqqueue* queue)
{
	if (queue == nullptr || queue->size == 0)
	{
		return nullptr;
	}
	return queue->data[queue->size - 1];
}
//���ش�С
int Size_Seqqueue(Seqqueue* queue)
{
	if (queue == nullptr)
	{
		return -1;
	}
	return queue->size;
}
//��ն���
void clear_Seqqueue(Seqqueue* queue)
{
	if (queue == nullptr)
	{
		return;
	}
	queue->size = 0;
}
//���ٶ���
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
	//��������
	Seqqueue* queue = Init_seqqueue();
	//��������
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
	cout << "Ŀǰ��β��Ԫ����" << prear->name << endl;
	while (queue->size > 0)
	{
		//����ջ��Ԫ��
		Person* per = (Person*)Front_Seqqueue(queue);
		cout << per->name << endl;
		//����Ԫ��
		Pop_Seqqueue(queue);
	}

	return 0;
}
#endif