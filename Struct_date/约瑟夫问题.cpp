#if 0;
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
//����������
#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

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
typedef struct PERSON
{
	CircleLinkNode node;
	char name[64];
	int age;
	int socer;
}Person;
typedef int(*COMPARE)(CircleLinkNode* c1, CircleLinkNode* c2);
typedef void(*PRINT)(CircleLinkNode* c1);

void Myprint(CircleLinkNode* n)
{
	Person* p = (Person*)n;
	cout << p->name << " ";
	cout << p->age << " ";
	cout << p->socer << endl;


}
int Mycompare(CircleLinkNode* c1, CircleLinkNode* c2)
{
	Person* p1 = (Person*)c1;
	Person* p2 = (Person*)c2;

	if (p1->socer == p2->socer && p1->age == p2->age == strcmp(p1->name, p2->name) == 0)
		return CIRCLELINKLIST_TRUE;
	return CIRCLELINKLIST_FALSE;
}


//��ʼ������
CircleLinkList* Init_CircleList();
//���뺯��
void Insert_CircleList(CircleLinkList* list, int pos, CircleLinkNode* data);
//��õ�һ��Ԫ��
CircleLinkNode* Front_CircleLinkNode(CircleLinkList* clist);
//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos);
//����ֵ����ɾ��
void RemoveByValueCircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARE cmp);
//�������ĳ���
int Size_CircleList(CircleLinkList* list);
//����Ԫ��
int Find_CircleList(CircleLinkList* list, CircleLinkNode* data, COMPARE cmp);
//��ӡ�ڵ�
void Print_CircleList(CircleLinkList* list, PRINT prn);
//�ͷ��ڴ�
void Free_CircleList(CircleLinkList* list);
//�ж��Ƿ�Ϊ��
int IsEmpty_CircleList(CircleLinkList* list);


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
	if (list == NULL || data == NULL)
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
	if (list == NULL)
		return;
	CircleLinkNode* Pcurrent = list->head.next;
	for (int i = 0; i < list->size * 2; i++)
	{
		//if (Pcurrent->next == &list->head)���ѭ��ʱ��ֹһֱ��ӡ
		//	break;
		if (Pcurrent == &list->head)//��δ�ӡʱ����ֹ��ӡͷ�ڵ㡣
			Pcurrent = Pcurrent->next;
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
#define M 8
#define N 3
typedef struct mynumber
{
	CircleLinkNode node;
	int value;
};
void pri(CircleLinkNode* c)
{
	mynumber* num = (mynumber*)c;
	cout << num->value << "  ";
}
int cmp2(CircleLinkNode* c1, CircleLinkNode* c2)
{
	mynumber* p1 = (mynumber*)c1;
	mynumber* p2 = (mynumber*)c2;


	if (p1->value==p2->value)
		return CIRCLELINKLIST_TRUE;
	return CIRCLELINKLIST_FALSE;
}
int main(void)
{
	//����ѭ������
	CircleLinkList* list = Init_CircleList();
	//�����������
	mynumber num[M];
	for(int i = 0; i < M; i++)
	{
		num[i].value = i + 1;
		Insert_CircleList(list, i, (CircleLinkNode*)&num[i]);
	}
	int index = 1;
	//����ָ��
	CircleLinkNode* Pcurrent = list->head.next;
	while (Size_CircleList(list) != 1)
	{
		if (Pcurrent == &list->head)
			Pcurrent = Pcurrent->next;
		if (index == N)
		{
			RemoveByValueCircleLinkList(list, Pcurrent, cmp2);
			index = 0;
		}
		
		Pcurrent = Pcurrent->next;
		index++;
	}
	Print_CircleList(list, pri);

	//�ͷ������ڴ�
	Free_CircleList(list); 
	return 0;
}
#endif