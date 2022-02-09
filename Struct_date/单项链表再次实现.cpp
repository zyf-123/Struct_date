#if 0;
#include<iostream>
using namespace std;

typedef struct  LINKNODE
{
	//int data;
	void* data;//������ָ�룬����ָ���κ����͵�����
	LINKNODE* next;
}LinkNode;
typedef struct LINKLIST
{
	LinkNode* head;
	int size;
}LinkList;

typedef void (*PRINTLINKNODE)(void*);//��ӡ����ָ��

//��ʼ������
LinkList* Init_Linklist();
//ָ��λ�ò�������
void Insert_LinkList(LinkList* list, int pos, void* data);
//ɾ���ƶ�λ�õ�ֵ
void Remove_Linklist(LinkList* list, int pos);
//�������ĳ���
int Size_Linklist(LinkList* list);
//����
int Find_Linklist(LinkList* list, void* data);
//���ص�һ���ڵ������
void* Front_Linklist(LinkList* list);
//��ӡ�б�ڵ�
void Print_Linklist(LinkList* list, PRINTLINKNODE print);
//�ͷ������ڴ�
void Free_Linklist(LinkList* list);




//��ʼ������
LinkList* Init_Linklist()
{
	LinkList* list = new LinkList;
	list->head = new LinkNode;
	list->head->data = NULL;
	list->head->next = NULL;
	list->size = 0;
	//ͷ�ڵ㣬������������Ϣ
	return list;
}

//ָ��λ�ò�������
void Insert_LinkList(LinkList* list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
		return;

	//���posԽ�磬Ĭ�ϲ嵽β��
	if (pos < 0 || pos>list->size)
	{
		pos = list->size;
	}
	//����һ���µĽڵ�
	LinkNode* newnode = new LinkNode;
	newnode->data = data;
	newnode->next = NULL;
	//Ѱ��һ���ڵ㣬��Ҫһ������ָ��
	LinkNode* Pcurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	//�µĽڵ�����б�
	newnode->next = Pcurrent->next;
	Pcurrent->next = newnode;
	list->size++;

}

//ɾ���ƶ�λ�õ�ֵ
void Remove_Linklist(LinkList* list, int pos)
{
	if (list == NULL)
		return;
	if (pos < 0 || pos >= list->size)
		return;
	//����ָ��
	LinkNode* Pcurrent = list->head;
	//Ѱ��ǰһ���ڵ�
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	//��ʱָ�룬�����ͷű���
	LinkNode* temp = Pcurrent->next;
	Pcurrent->next = Pcurrent->next->next;
	delete temp;
	list->size--;
}

//�������ĳ���
int Size_Linklist(LinkList* list)
{
	return list->size;
}


//����
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

//���ص�һ���ڵ������
void* Front_Linklist(LinkList* list)
{
	return list->head->next->data;
}

//��ӡ�б�ڵ�
void Print_Linklist(LinkList* list, PRINTLINKNODE print)
{
	if (list == NULL)
		return;
	//����ָ�����
	LinkNode* Pcurrent = list->head->next;
	while (Pcurrent != NULL)
	{
		print(Pcurrent->data);
		Pcurrent = Pcurrent->next;
	}
}

//�ͷ������ڴ�
void Free_Linklist(LinkList* list)
{
	if (list == NULL)
		return;
	//����ָ�����
	LinkNode* Pcurrent = list->head;
	while (Pcurrent != NULL)
	{
		//������һ���ڵ��λ��
		LinkNode* temp = Pcurrent->next;
		delete Pcurrent;
		Pcurrent = temp;
	}
	delete list;
}


//�Զ���һ����������
typedef struct PERSON
{
	char name[64];
	int age;
	int socer;
}Person;
//��ӡ����
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
	//������������
	PERSON p1 = { "z",18,100 };
	PERSON p2 = { "y",14,30 };
	PERSON p3 = { "f",16,80 };
	PERSON p4 = { "z",17,15 };
	PERSON p5 = { "zz",28,10 };

	//���ݲ����б�
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	
	Print_Linklist(list, myprint);
	Remove_Linklist(list,2);//ɾ���ڶ���λ�õĽڵ�
	cout<<Size_Linklist(list);
	cout << "ɾ��������" << endl;
	Print_Linklist(list, myprint);
	Free_Linklist(list);



	return 0;
}
#endif