#if 0;
#include<iostream>
using namespace std;

typedef struct  LINKNODE
{
	//int data;
	void* data;//无类型指针，可以指向任何类型的数据
	LINKNODE* next;
}LinkNode;
typedef struct LINKLIST
{
	LinkNode* head;
	int size;
}LinkList;

typedef void (*PRINTLINKNODE)(void*);//打印函数指针

//初始化链表
LinkList* Init_Linklist();
//指定位置插入数据
void Insert_LinkList(LinkList* list, int pos, void* data);
//删除制定位置的值
void Remove_Linklist(LinkList* list, int pos);
//获得链表的长度
int Size_Linklist(LinkList* list);
//查找
int Find_Linklist(LinkList* list, void* data);
//返回第一个节点的数据
void* Front_Linklist(LinkList* list);
//打印列表节点
void Print_Linklist(LinkList* list, PRINTLINKNODE print);
//释放链表内存
void Free_Linklist(LinkList* list);




//初始化链表
LinkList* Init_Linklist()
{
	LinkList* list = new LinkList;
	list->head = new LinkNode;
	list->head->data = NULL;
	list->head->next = NULL;
	list->size = 0;
	//头节点，不保存数据信息
	return list;
}

//指定位置插入数据
void Insert_LinkList(LinkList* list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
		return;

	//如果pos越界，默认插到尾部
	if (pos < 0 || pos>list->size)
	{
		pos = list->size;
	}
	//创建一个新的节点
	LinkNode* newnode = new LinkNode;
	newnode->data = data;
	newnode->next = NULL;
	//寻找一个节点，需要一个辅助指针
	LinkNode* Pcurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	//新的节点进入列表
	newnode->next = Pcurrent->next;
	Pcurrent->next = newnode;
	list->size++;

}

//删除制定位置的值
void Remove_Linklist(LinkList* list, int pos)
{
	if (list == NULL)
		return;
	if (pos < 0 || pos >= list->size)
		return;
	//辅助指针
	LinkNode* Pcurrent = list->head;
	//寻找前一个节点
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	//临时指针，用来释放变量
	LinkNode* temp = Pcurrent->next;
	Pcurrent->next = Pcurrent->next->next;
	delete temp;
	list->size--;
}

//获得链表的长度
int Size_Linklist(LinkList* list)
{
	return list->size;
}


//查找
int Find_Linklist(LinkList* list, void* data)
{
	if (list == NULL)
		return -1;
	if (data == NULL)
		return -1;
	LinkNode* Pcurrent = list->head->next;
	int i = 0;
	while (Pcurrent != NULL)
	{
		if (Pcurrent->data == data)
			break;
		i++;
		Pcurrent = Pcurrent->next;
	}
	return i;
}

//返回第一个节点的数据
void* Front_Linklist(LinkList* list)
{
	return list->head->next->data;
}

//打印列表节点
void Print_Linklist(LinkList* list, PRINTLINKNODE print)
{
	if (list == NULL)
		return;
	//辅助指针变量
	LinkNode* Pcurrent = list->head->next;
	while (Pcurrent != NULL)
	{
		print(Pcurrent->data);
		Pcurrent = Pcurrent->next;
	}
}

//释放链表内存
void Free_Linklist(LinkList* list)
{
	if (list == NULL)
		return;
	//辅助指针变量
	LinkNode* Pcurrent = list->head;
	while (Pcurrent != NULL)
	{
		//缓存下一个节点的位置
		LinkNode* temp = Pcurrent->next;
		delete Pcurrent;
		Pcurrent = temp;
	}
	delete list;
}


//自定义一个数据类型
typedef struct PERSON
{
	char name[64];
	int age;
	int socer;
}Person;
//打印函数
void  myprint(void* data)
{
	PERSON* p = (PERSON*)data;
	cout << "name:" << p->name << "  ";
	cout << "age:" << p->age << "  ";
	cout << "socer:" << p->socer << endl;

}
int main(void)
{

	LinkList* list = Init_Linklist();
	//创建几个数据
	PERSON p1 = { "z",18,100 };
	PERSON p2 = { "y",14,30 };
	PERSON p3 = { "f",16,80 };
	PERSON p4 = { "z",17,15 };
	PERSON p5 = { "zz",28,10 };

	//数据插入列表
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	
	Print_Linklist(list, myprint);
	Remove_Linklist(list,2);//删除第二个位置的节点
	cout<<Size_Linklist(list);
	cout << "删除后的情况" << endl;
	Print_Linklist(list, myprint);
	Free_Linklist(list);



	return 0;
}
#endif