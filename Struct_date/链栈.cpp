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


//初始化函数
LinkStack* Init_LinkStack();
//入栈
void Push_LinkStack(LinkStack* stack, LinkNode* data);
//出栈
 void Pop_LinkStack(LinkStack* stack);
//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack);
//返回栈元素的个数
int  Size_LinkStack(LinkStack* stack);
//清空栈
void Clear_LinkStack(LinkStack* stack);
//销毁栈
void FreeSpace_LinkStack(LinkStack* stack);

//初始化函数
LinkStack* Init_LinkStack()
{
	LinkStack* stack = new LinkStack;
	stack->head.next = NULL;
	stack->size = 0;
	return stack;
}
//入栈
void Push_LinkStack(LinkStack* stack, LinkNode* data)
{
	if (stack == NULL||data==NULL)
		return;
	data->next = stack->head.next;
	stack->head.next = data;
	stack->size++;
}
//出栈
void Pop_LinkStack(LinkStack* stack)
{
	if (stack == NULL || stack->size==0)
		return;
	//第一个有效节点
	LinkNode* Pnext = stack->head.next;
	stack->head.next = Pnext->next;
	stack->size--;
}
//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack)
{
	if (stack == NULL || stack->size == 0)
		return NULL;
	//第一个有效节点
	LinkNode* Pnext = stack->head.next;
	return Pnext;
}
//返回栈元素的个数
int  Size_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
		return -1;
	return stack->size;
}
//清空栈
void Clear_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
		return ;
	stack->head.next = NULL;
	stack->size = 0;
}
//销毁栈
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
	//创建栈 
	LinkStack* stack = Init_LinkStack();
	//数据入栈
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

	//输出
	while (stack->size > 0)
	{
		//访问栈顶元素
		Person* per = (Person*)Top_LinkStack(stack);
		cout << per->name << endl;
		//弹出元素
		Pop_LinkStack(stack);

	}
	//释放内存
	FreeSpace_LinkStack(stack);
	return 0;
}
#endif