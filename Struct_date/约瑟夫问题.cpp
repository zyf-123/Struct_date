#if 0;
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
//定义俩个宏
#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

//链表内的节点
typedef struct CIRCLELINKNODE
{
	CIRCLELINKNODE* next;

}CircleLinkNode;
//链表的结构体
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


//初始化函数
CircleLinkList* Init_CircleList();
//插入函数
void Insert_CircleList(CircleLinkList* list, int pos, CircleLinkNode* data);
//获得第一个元素
CircleLinkNode* Front_CircleLinkNode(CircleLinkList* clist);
//根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos);
//根据值进行删除
void RemoveByValueCircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARE cmp);
//获得链表的长度
int Size_CircleList(CircleLinkList* list);
//查找元素
int Find_CircleList(CircleLinkList* list, CircleLinkNode* data, COMPARE cmp);
//打印节点
void Print_CircleList(CircleLinkList* list, PRINT prn);
//释放内存
void Free_CircleList(CircleLinkList* list);
//判断是否为空
int IsEmpty_CircleList(CircleLinkList* list);


//初始化函数
CircleLinkList* Init_CircleList()
{
	CircleLinkList* list = new CircleLinkList;
	list->head.next = &(list->head);
	list->size = 0;
	return list;
}
//插入函数
void Insert_CircleList(CircleLinkList* list, int pos, CircleLinkNode* data)
{
	if (list == NULL || data == NULL)
		return;
	if (pos<0 || pos>list->size)
		pos = list->size;
	//辅助指针变量
	CircleLinkNode* Pcurrent = &list->head;
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	data->next = Pcurrent->next;
	Pcurrent->next = data;
	list->size++;


}
//获得第一个元素
CircleLinkNode* Front_CircleLinkNode(CircleLinkList* clist)
{
	return clist->head.next;
}
//根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos)
{
	if (clist == NULL)
		return;
	if (pos < 0 || pos >= clist->size)
		return;
	//辅助指针变量
	CircleLinkNode* Pcurrent = &clist->head;
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	Pcurrent->next = Pcurrent->next->next;
	clist->size--;
}
//根据值进行删除
void RemoveByValueCircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARE cmp)
{
	if (clist == NULL)
		return;
	if (data == NULL)
		return;
	//循环列表中，要避免一直循环。
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
//获得链表的长度
int Size_CircleList(CircleLinkList* list)
{
	return list->size;
}
//查找元素
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
//打印节点
void Print_CircleList(CircleLinkList* list, PRINT prn)
{
	if (list == NULL)
		return;
	CircleLinkNode* Pcurrent = list->head.next;
	for (int i = 0; i < list->size * 2; i++)
	{
		//if (Pcurrent->next == &list->head)多次循环时防止一直打印
		//	break;
		if (Pcurrent == &list->head)//多次打印时，防止打印头节点。
			Pcurrent = Pcurrent->next;
		prn(Pcurrent);
		Pcurrent = Pcurrent->next;
	}
}
//释放内存
void Free_CircleList(CircleLinkList* list)
{
	if (list == NULL)
		return;
	delete list;
}
//判断是否为空
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
	//创建循环链表
	CircleLinkList* list = Init_CircleList();
	//链表插入数据
	mynumber num[M];
	for(int i = 0; i < M; i++)
	{
		num[i].value = i + 1;
		Insert_CircleList(list, i, (CircleLinkNode*)&num[i]);
	}
	int index = 1;
	//辅助指针
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

	//释放链表内存
	Free_CircleList(list); 
	return 0;
}
#endif