#include<iostream>
using namespace std;

//�����ڵĽڵ�
typedef struct CIRCLELINKNODE
{
	CIRCLELINKNODE* next;

}CircleLinkNode;
//����Ľṹ��
typedef struct CIRCLELINKLIST
{
	CircleLinkNode head;
	int size;
}CircleLinkList;
typedef int(*COMPARE)(CircleLinkNode* c1, CircleLinkNode* c2);
typedef void(*PRINT)(CircleLinkNode* c1);
//����������
#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

//��ʼ������
CircleLinkList* Init_CircleList();
//���뺯��
void Insert_CircleList(CircleLinkList* list, int pos, CircleLinkNode* data);
//��õ�һ��Ԫ��
CircleLinkNode* Front_CircleLinkNode(CircleLinkList* clist);
//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist,int pos);
//����ֵ����ɾ��
void RemoveByValueCircleLinkList(CircleLinkList* clist, CircleLinkNode* data,COMPARE cmp);
//�������ĳ���
int Size_CircleList(CircleLinkList* list);
//����Ԫ��
int Find_CircleList(CircleLinkList* list, CircleLinkNode* data, COMPARE cmp);
//��ӡ�ڵ�
void Print_CircleList(CircleLinkList* list,PRINT prn );
//�ͷ��ڴ�
void Free_CircleList(CircleLinkList* list);
//�ж��Ƿ�Ϊ��
int IsEmpty_CircleList(CircleLinkList * list);


//��ʼ������
CircleLinkList* Init_CircleList()
{
	CircleLinkList* list = new CircleLinkList;
	list->head.next = &(list->head);
	list->size = 0;
	return list;
}
//���뺯��
void Insert_CircleList(CircleLinkList* list, int pos, CircleLinkNode* data)
{
	if (list == NULL||data==NULL)
		return;
	if (pos<0 || pos>list->size)
		pos = list->size;
	//����ָ�����
	CircleLinkNode* Pcurrent = &list->head;
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	data->next = Pcurrent->next;
	Pcurrent->next = data;
	list->size++;


}
//��õ�һ��Ԫ��
CircleLinkNode* Front_CircleLinkNode(CircleLinkList* clist)
{
	return clist->head.next;
}
//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos)
{
	if (clist == NULL)
		return;
	if (pos < 0 || pos >= clist->size)
		return;
	//����ָ�����
	CircleLinkNode* Pcurrent = &clist->head;
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	Pcurrent->next = Pcurrent->next->next;
	clist->size--;
}
//����ֵ����ɾ��
void RemoveByValueCircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARE cmp)
{
	if (clist == NULL)
		return;
	if (data == NULL)
		return;
	//ѭ���б��У�Ҫ����һֱѭ����
	CircleLinkNode* Pcurrent = &clist->head;
	while (Pcurrent->next != &clist->head)
	{
		if (cmp(Pcurrent->next, data) == CIRCLELINKLIST_TRUE)
			break;
		Pcurrent = Pcurrent->next;
	}
	Pcurrent->next = Pcurrent->next->next;
	clist->size--;


}
//�������ĳ���
int Size_CircleList(CircleLinkList* list)
{
	return list->size;
}
//����Ԫ��
int Find_CircleList(CircleLinkList* list, CircleLinkNode* data, COMPARE cmp)
{
	if (list == NULL || data == NULL)
		return -1;
	CircleLinkNode* Pcurrent = list->head.next;
	for (int i = 0; i < list->size; i++)
	{
		if (cmp(data, Pcurrent) == CIRCLELINKLIST_TRUE)
		{
			return i;
		}
		Pcurrent = Pcurrent->next;
	}
	return -1;

}
//��ӡ�ڵ�
void Print_CircleList(CircleLinkList* list, PRINT prn)
{
	if (list == NULL )
		return;
	CircleLinkNode* Pcurrent = list->head.next;
	for (int i = 0; i < list->size; i++)
	{
		//if (Pcurrent->next == &list->head)���ѭ��ʱ��ֹһֱ��ӡ
		//	break;
		prn(Pcurrent);
		Pcurrent = Pcurrent->next;
	}
}
//�ͷ��ڴ�
void Free_CircleList(CircleLinkList* list)
{
	if (list == NULL)
		return;
	delete list;
}
//�ж��Ƿ�Ϊ��
int IsEmpty_CircleList(CircleLinkList* list)
{
	if (list->size == 0)
		return CIRCLELINKLIST_TRUE;
	return CIRCLELINKLIST_FALSE;

}
int main(void)
{
	CircleLinkList *list =In
}

