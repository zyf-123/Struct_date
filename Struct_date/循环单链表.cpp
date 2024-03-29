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
	cout << p->name<<" ";
	cout << p->age << " ";
	cout << p->socer << endl;


}
int Mycompare(CircleLinkNode* c1, CircleLinkNode* c2)
{
	Person * p1 = (Person*)c1;
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
void RemoveByPos_CircleLinkList(CircleLinkList* clist,int pos);
//根据值进行删除
void RemoveByValueCircleLinkList(CircleLinkList* clist, CircleLinkNode* data,COMPARE cmp);
//获得链表的长度
int Size_CircleList(CircleLinkList* list);
//查找元素
int Find_CircleList(CircleLinkList* list, CircleLinkNode* data, COMPARE cmp);
//打印节点
void Print_CircleList(CircleLinkList* list,PRINT prn );
//释放内存
void Free_CircleList(CircleLinkList* list);
//判断是否为空
int IsEmpty_CircleList(CircleLinkList * list);


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
	if (list == NULL||data==NULL)
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
	if (list == NULL )
		return;
	CircleLinkNode* Pcurrent = list->head.next;
	for (int i = 0; i < list->size*2; i++)
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

int main(void)
{
	//创建一个循环链表
	CircleLinkList* list = Init_CircleList();
	//创建数据
	Person p1,p2, p3, p4, p5;
	strcpy(p1.name, "zyf");
	strcpy(p2.name, "z");
	strcpy(p3.name, "y");
	strcpy(p4.name, "y");
	strcpy(p5.name, "zzz");
	
	p1.age = 11;
	p2.age = 12;
	p3.age = 13;
	p4.age = 14;
	p5.age = 15;
	p1.socer = 10;
	p2.socer = 20;
	p3.socer = 30;
	p4.socer = 40;
	p5.socer = 50;
	//数据进入链表
	Insert_CircleList(list, 100, (CircleLinkNode*)&p1);
	Insert_CircleList(list, 100, (CircleLinkNode*)&p2);
	Insert_CircleList(list, 100, (CircleLinkNode*)&p3);
	Insert_CircleList(list, 100, (CircleLinkNode*)&p4);
	Insert_CircleList(list, 100, (CircleLinkNode*)&p5);

	//打印链表
	Print_CircleList(list, Myprint);

	Person pdel;
	strcpy(pdel.name, "zyf");
	pdel.socer = 10;
	pdel.age = 11;
	RemoveByValueCircleLinkList(list, (CircleLinkNode*)&pdel, Mycompare);

	cout << "删除后" << endl;
	Print_CircleList(list, Myprint);

	//释放内存
	Free_CircleList(list);


}

#endif 