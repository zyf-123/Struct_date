#if 0;
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
typedef struct LINKNODE
{
	struct LINKNODE* next;

}LinkNode;

typedef struct LINKSTACK
{
	LinkNode head;
	int size;

}LinkStack;


//��ʼ������
LinkStack* Init_LinkStack();
//��ջ
void Push_LinkStack(LinkStack* stack, LinkNode* data);
//��ջ
 void Pop_LinkStack(LinkStack* stack);
//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack);
//����ջԪ�صĸ���
int  Size_LinkStack(LinkStack* stack);
//���ջ
void Clear_LinkStack(LinkStack* stack);
//����ջ
void FreeSpace_LinkStack(LinkStack* stack);

//��ʼ������
LinkStack* Init_LinkStack()
{
	LinkStack* stack = new LinkStack;
	stack->head.next = NULL;
	stack->size = 0;
	return stack;
}
//��ջ
void Push_LinkStack(LinkStack* stack, LinkNode* data)
{
	if (stack == NULL||data==NULL)
		return;
	data->next = stack->head.next;
	stack->head.next = data;
	stack->size++;
}
//��ջ
void Pop_LinkStack(LinkStack* stack)
{
	if (stack == NULL || stack->size==0)
		return;
	//��һ����Ч�ڵ�
	LinkNode* Pnext = stack->head.next;
	stack->head.next = Pnext->next;
	stack->size--;
}
//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack)
{
	if (stack == NULL || stack->size == 0)
		return NULL;
	//��һ����Ч�ڵ�
	LinkNode* Pnext = stack->head.next;
	return Pnext;
}
//����ջԪ�صĸ���
int  Size_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
		return -1;
	return stack->size;
}
//���ջ
void Clear_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
		return ;
	stack->head.next = NULL;
	stack->size = 0;
}
//����ջ
void FreeSpace_LinkStack(LinkStack* stack)
{
	delete(stack);
}
typedef struct Person
{
	LinkNode node;
	char name[64];
};
int main(void)
{
	//����ջ 
	LinkStack* stack = Init_LinkStack();
	//������ջ
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	Push_LinkStack(stack, (LinkNode*)&p1);
	Push_LinkStack(stack, (LinkNode*)&p2);
	Push_LinkStack(stack, (LinkNode*)&p3);
	Push_LinkStack(stack, (LinkNode*)&p4);
	Push_LinkStack(stack, (LinkNode*)&p5);

	//���
	while (stack->size > 0)
	{
		//����ջ��Ԫ��
		Person* per = (Person*)Top_LinkStack(stack);
		cout << per->name << endl;
		//����Ԫ��
		Pop_LinkStack(stack);

	}
	//�ͷ��ڴ�
	FreeSpace_LinkStack(stack);
	return 0;
}
#endif