#if 0;
#include<iostream>
#include<iomanip>
#pragma warning (disable:4996)
using namespace std;
//链表节点
typedef struct  LINKNODE
{
	LINKNODE* next;
}Linknode;

typedef struct LINKLIST
{
	LINKNODE head;
	int size;
}LinkList;

typedef struct PERSON
{
	Linknode node;//类似一个挂钩
	char name[64];//偏移量在地下
	int age;//偏移量
}Person;

void Myprint(Linknode* data )
{
	Person* p = (Person*)data;
	cout << setw(4) << p->name;
	cout << p->age << "  ";
}
int cmp(Linknode* l1, Linknode* l2)
{
	Person* p1 = (Person*)l1;
	Person* p2 = (Person*)l2;
	if (strcmp((p1->name), p2->name)==0 && p1->age == p2->age)
		return 0;
	else 
		return -1;

 }
//编译函数指针
//比较函数指针
typedef int (*Mycompare)(Linknode* ,Linknode *);
typedef void (*Print)(Linknode*);
//初始化链表
LinkList* Init_Linklist();
//插入
void Insert_Linklist(LinkList* list, int pos, Linknode* data);//插入的是LINKNODE*的数据
//删除
void Remove_linklist(LinkList* list, int pos);
//返回链表的大小
int Size_Linklist(LinkList* list);
//打印
void Print_Linklist(LinkList* list, Print print);
//释放链表内存
void FreeSpace_Linklist(LinkList* list);
//查找
int Find_Linklist(LinkList* list, Linknode* data, Mycompare cmp);


LinkList* Init_Linklist()
{
	LinkList* list = new LinkList;
	list->head.next = NULL;
	list->size = 0;
	return list;
}

void Insert_Linklist(LinkList* list, int pos, Linknode* data)//不需要在创建一个新的辅助节点了
{
	if (list == NULL)
		return;
	if (data == NULL)
		return;
	if (pos<0 || pos>list->size)
		pos = list->size;
	
	//查找插入位置
	Linknode* Pcurrent = (&list->head);//结构体取地址
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	//插入新节点
	data->next = Pcurrent->next;
	Pcurrent->next = data;

	list->size++;

}
//删除
void Remove_linklist(LinkList* list, int pos)
{
	if (list == NULL)
		return;
	if (pos < 0 || pos >= list->size)
		return;
	//辅助指针变量
	Linknode* Pcurrent = &list->head;
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	Pcurrent->next=Pcurrent->next->next;
	list->size--;
}
//返回链表的大小
int Size_Linklist(LinkList* list);
void Print_Linklist(LinkList* list, Print print)
{
	if (list == NULL)
		return;
	
	//辅助指针
	Linknode* Pcurrent = (&list->head)->next;
	while (Pcurrent != NULL)
	{
		print(Pcurrent);
		Pcurrent = Pcurrent->next;
	}



	
}
//释放链表内存
void FreeSpace_Linklist(LinkList* list)
{
	if (list == NULL)
		return;
	//不需要每次释放节点了，因为没有每次创建新的节点，节点都保存在mydata中
	delete list;
}
//查找
int Find_Linklist(LinkList* list, Linknode* data,Mycompare cmp)
{
	if (list == NULL)
		return -1;
	if (data == NULL)
		return -1;
	//辅助指针
	Linknode* Pcurrent = list->head.next;
	int i = 0;
	int flag = -1;
	while (Pcurrent != NULL)
	{
		if (cmp(Pcurrent, data) == 0)
		{
			flag = i;
			break;
		}
		i++;
		Pcurrent = Pcurrent->next;
	}
	return flag;
}


int main(void)
{
	LinkList* list = Init_Linklist();
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "z");
	strcpy(p2.name, "y");
	strcpy(p3.name, "f");
	strcpy(p4.name, "zz");
	strcpy(p5.name, "zyf");
	p1.age = 18;
	p2.age = 19;
	p3.age = 20;
	p4.age = 21;
	p5.age = 22;
	//将节点插入链表
	Insert_Linklist(list, 0, (Linknode*)&p1);
	Insert_Linklist(list, 0, (Linknode*)&p2);
	Insert_Linklist(list, 0, (Linknode*)&p3);
	Insert_Linklist(list, 0, (Linknode*)&p4);
	Insert_Linklist(list, 0, (Linknode*)&p5);

	Print_Linklist(list, Myprint);
	Person pfind;
	strcpy(pfind.name, "zz");
	pfind.age = 21;
	cout<<"位置是："<<Find_Linklist(list, (Linknode*)&pfind, cmp);
	Remove_linklist(list, 3);
	cout <<endl<<"删除后" << endl;
	Print_Linklist(list, Myprint);
	FreeSpace_Linklist(list);
	



	return 0;
}
#endif