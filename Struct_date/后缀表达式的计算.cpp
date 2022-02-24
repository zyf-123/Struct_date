#if 0;
/*基于后缀表达式的计算问题
对于数字全部进栈
对于符号，从栈中弹出右操作数，然后从栈中弹出左操作数，根据符号进行相应的计算，然后运算结果在次压入栈中
直到剩下一个值*/
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
	if (stack == NULL || data == NULL)
		return;
	data->next = stack->head.next;
	stack->head.next = data;
	stack->size++;
}
//出栈
void Pop_LinkStack(LinkStack* stack)
{
	if (stack == NULL || stack->size == 0)
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
		return;
	stack->head.next = NULL;
	stack->size = 0;
}
//销毁栈
void FreeSpace_LinkStack(LinkStack* stack)
{
	delete(stack);
}
//判断是否是数字
int IsNumber(char c)
{
	return c >= '0' && c <= '9';
}
typedef struct MyNum
{
	LinkNode* node;
	int num;
};
int Caculate(char c,int left,int right)
{
	int ret = 0;
	switch (c)
	{
	case '+':
		ret = left + right;
		break;
	case'-':
		ret = left - right;
		break;
	case'*':
		ret = left * right;
		break;
	case'/':
		ret = left / right;
		break;
	default:
		break;
	}
	return ret;
}
int main(void)
{
	//后缀表达式
	char* str = (char *)"831-5*+";
	char* p = str;
	//创建栈
	LinkStack* stack = Init_LinkStack();
	while (*p != '\0')
	{
		//如果是数字直接入栈
		if (IsNumber(*p))
		{
			MyNum* num = new MyNum;
			num->num = *p-'0';//ANSCII
			Push_LinkStack(stack, (LinkNode*)num);
		}
		else
		{
			//先从栈中弹出右边操作数
			MyNum* right = (MyNum*)Top_LinkStack(stack);
			int right_num = right->num;
			Pop_LinkStack(stack);
			delete right;
			//然后取出右操作数
			MyNum* left = (MyNum*)Top_LinkStack(stack);
			int left_num = left->num;
			Pop_LinkStack(stack);
			delete left;
			int ret = Caculate(*p,left_num, right_num);
			//结果入栈
			MyNum* num = new MyNum;
			num->num = ret;
			Push_LinkStack(stack, (LinkNode*)num);

		}
		p++;
	}
	if (Size_LinkStack(stack) == 1)
	{
		MyNum* mynum = (MyNum*)Top_LinkStack(stack);
		cout << "运算结果是:" << mynum->num << endl;
		Pop_LinkStack(stack);
		delete mynum;
	}
	//释放栈
	FreeSpace_LinkStack(stack);
	return 0;
}
#endif