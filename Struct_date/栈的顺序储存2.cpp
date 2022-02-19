#if 0;
#include<iostream>
#pragma warning (disable:4996)
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0

using namespace std;
//������ȥģ��ջ��˳�򴢴�
#define MAX_SIZE 1024

typedef struct SEQSTACK
{
	void* data[MAX_SIZE];
	int size;

}Seqstack;
//��ʼ��ջ
Seqstack* Init_Seqstack();
//��ջ����
void Push_Seqstack(Seqstack* stack,void* data);
//����ջ��Ԫ��
void* Top_Seqstack(Seqstack* stack);
//��ջ
void Pop_Seqstack(Seqstack* stack);
//�ж��Ƿ�Ϊ��
int IsEmpty(Seqstack* stack);
//����ջ��Ԫ�صĸ���
int Size_SeqStack(Seqstack* stack);
//����
void FreeSeqStack(Seqstack* stack);
//���
void Clear_SeqStack(Seqstack* stack);

//��ʼ��ջ
Seqstack* Init_Seqstack()
{
	Seqstack* stack = new Seqstack;
	stack->data[MAX_SIZE] = { NULL };
	stack->size = 0;
	return stack;
}
//��ջ����
void Push_Seqstack(Seqstack* stack, void* data)
{
	if (stack->size == MAX_SIZE || stack == NULL || data == NULL)
		return;
	stack->data[stack->size] = data;
	stack->size++;
}
//����ջ��Ԫ��
void* Top_Seqstack(Seqstack* stack)
{
	if (stack == NULL||stack->size==0)
		return NULL;
	return stack->data[stack->size-1];
}
//��ջ
void Pop_Seqstack(Seqstack* stack)
{
	if (stack->size == 0 || stack == NULL )
		return;
	 stack->size-- ;
}
//�ж��Ƿ�Ϊ��
int IsEmpty(Seqstack* stack)
{
	if (stack->size == 0)
		return SEQSTACK_TRUE;
	return SEQSTACK_FALSE;
}
//����ջ��Ԫ�صĸ���
int Size_SeqStack(Seqstack* stack)
{
	return stack->size;
}
//����
void FreeSeqStack(Seqstack* stack)
{
	delete stack;
}
//���
void Clear_SeqStack(Seqstack* stack)
{
	if (stack == NULL)
		return;
	stack->size = 0;
}
typedef struct Person
{
	char name[64];
};
int main(void)
{
	//����ջ 
	Seqstack* stack = Init_Seqstack();
	//������ջ
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");
	Push_Seqstack(stack, &p1);
	Push_Seqstack(stack, &p2);
	Push_Seqstack(stack, &p3);
	Push_Seqstack(stack, &p4);
	Push_Seqstack(stack, &p5);

	//���
	while (stack->size > 0)
	{
		//����ջ��Ԫ��
		Person * per =(Person*)Top_Seqstack(stack);
		cout << per->name << endl;
		//����Ԫ��
		Pop_Seqstack(stack);

	}
	//�ͷ��ڴ�
	FreeSeqStack(stack);

	return 0;
}
#endif