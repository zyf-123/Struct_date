#if 0;
#include<iostream>
#include<iomanip>
#pragma warning (disable:4996)
using namespace std;
//����ڵ�
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
	Linknode node;//����һ���ҹ�
	char name[64];//ƫ�����ڵ���
	int age;//ƫ����
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
//���뺯��ָ��
//�ȽϺ���ָ��
typedef int (*Mycompare)(Linknode* ,Linknode *);
typedef void (*Print)(Linknode*);
//��ʼ������
LinkList* Init_Linklist();
//����
void Insert_Linklist(LinkList* list, int pos, Linknode* data);//�������LINKNODE*������
//ɾ��
void Remove_linklist(LinkList* list, int pos);
//��������Ĵ�С
int Size_Linklist(LinkList* list);
//��ӡ
void Print_Linklist(LinkList* list, Print print);
//�ͷ������ڴ�
void FreeSpace_Linklist(LinkList* list);
//����
int Find_Linklist(LinkList* list, Linknode* data, Mycompare cmp);


LinkList* Init_Linklist()
{
	LinkList* list = new LinkList;
	list->head.next = NULL;
	list->size = 0;
	return list;
}

void Insert_Linklist(LinkList* list, int pos, Linknode* data)//����Ҫ�ڴ���һ���µĸ����ڵ���
{
	if (list == NULL)
		return;
	if (data == NULL)
		return;
	if (pos<0 || pos>list->size)
		pos = list->size;
	
	//���Ҳ���λ��
	Linknode* Pcurrent = (&list->head);//�ṹ��ȡ��ַ
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	//�����½ڵ�
	data->next = Pcurrent->next;
	Pcurrent->next = data;

	list->size++;

}
//ɾ��
void Remove_linklist(LinkList* list, int pos)
{
	if (list == NULL)
		return;
	if (pos < 0 || pos >= list->size)
		return;
	//����ָ�����
	Linknode* Pcurrent = &list->head;
	for (int i = 0; i < pos; i++)
	{
		Pcurrent = Pcurrent->next;
	}
	Pcurrent->next=Pcurrent->next->next;
	list->size--;
}
//��������Ĵ�С
int Size_Linklist(LinkList* list);
void Print_Linklist(LinkList* list, Print print)
{
	if (list == NULL)
		return;
	
	//����ָ��
	Linknode* Pcurrent = (&list->head)->next;
	while (Pcurrent != NULL)
	{
		print(Pcurrent);
		Pcurrent = Pcurrent->next;
	}



	
}
//�ͷ������ڴ�
void FreeSpace_Linklist(LinkList* list)
{
	if (list == NULL)
		return;
	//����Ҫÿ���ͷŽڵ��ˣ���Ϊû��ÿ�δ����µĽڵ㣬�ڵ㶼������mydata��
	delete list;
}
//����
int Find_Linklist(LinkList* list, Linknode* data,Mycompare cmp)
{
	if (list == NULL)
		return -1;
	if (data == NULL)
		return -1;
	//����ָ��
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
	//���ڵ��������
	Insert_Linklist(list, 0, (Linknode*)&p1);
	Insert_Linklist(list, 0, (Linknode*)&p2);
	Insert_Linklist(list, 0, (Linknode*)&p3);
	Insert_Linklist(list, 0, (Linknode*)&p4);
	Insert_Linklist(list, 0, (Linknode*)&p5);

	Print_Linklist(list, Myprint);
	Person pfind;
	strcpy(pfind.name, "zz");
	pfind.age = 21;
	cout<<"λ���ǣ�"<<Find_Linklist(list, (Linknode*)&pfind, cmp);
	Remove_linklist(list, 3);
	cout <<endl<<"ɾ����" << endl;
	Print_Linklist(list, Myprint);
	FreeSpace_Linklist(list);
	



	return 0;
}
#endif