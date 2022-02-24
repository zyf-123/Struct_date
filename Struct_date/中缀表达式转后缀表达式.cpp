#if 0;
/*中缀表达式就是常见的数学表达式，但是把运算符放到数字的后面会更加符合计算机的运算
例如5+4= 就是一个中缀表达式 而它的后缀表达式应该是 5 4+    1+2*3 变成 1 2 3 * +
中缀转后缀的算法
对于数字直接输出 对于括号：左括号入栈。如果是运算符号的话，就与栈顶符号进行优先级比较，
如果栈顶符号优先级低，则此符号入栈，如果栈顶符号优先级高，则将栈顶的符号弹出输出，然后该符号入栈
右括号:将栈顶的符号弹出并输出，直到匹配到左括号*/
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


//判断是不是左括号
int IsLeft(char c)
{
	return c == '(';
}
//判断是不是右边括号
int IsRight(char c)
{
	return c == ')';
}
//判断是不是运算符号
int IsOperate(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
//返回运算符符号的优先级
int GetPriority(char c)
{
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	return 0;
}
typedef struct Mychar
{
	LinkNode node;
	char* p;
};
//数字的操作
void NumberOperate(char* p)
{
	cout << *p;
}
//创建Mychar
Mychar* CreatMychar(char* p)
{
	Mychar* mychar = new Mychar;
	mychar->p = p;
	return mychar;
}
//左括号的操作
void LeftOperate(LinkStack* stack, char* p)
{
	Mychar* mychar= CreatMychar(p);
	Push_LinkStack(stack,(LinkNode*)mychar);
}
//右括号操作
void RightOperate(LinkStack* stack)
{
	while (Size_LinkStack(stack) > 0)
	{
		Mychar* mychar = (Mychar*)Top_LinkStack(stack);
		//如果匹配到左括号，应该弹出
		if (IsLeft(*mychar->p))
		{
			Pop_LinkStack(stack);
			break;
		}
		else
		{
			cout << (*mychar->p);
			Pop_LinkStack(stack);
		}
		delete mychar;
	}
}
//运算符号的操作
void OperatorOperate(LinkStack* stack, char* p)
{
	Mychar* mychar= (Mychar*)Top_LinkStack(stack);
	//如果栈顶的有限级低于当前字符的优先级，直接入栈
	if (mychar == NULL)
	{
		Push_LinkStack(stack, (LinkNode*)CreatMychar(p));
		return;
	}
	if (GetPriority(*mychar->p) < GetPriority(*p))
	{
		Push_LinkStack(stack, (LinkNode*)CreatMychar(p));
		return;
	}
	//如果栈顶的优先级不低
	else
	{
		while (Size_LinkStack(stack) > 0)
		{
			Mychar* mychar2 =(Mychar*)Top_LinkStack(stack);

			//如果优先级低 当前符号入栈
			if (GetPriority(*mychar2->p) < GetPriority(*p))
			{
				Push_LinkStack(stack, (LinkNode*)CreatMychar(p));
				break;
			}
			//输出
			cout << (*mychar2->p);
			//弹出
			Pop_LinkStack(stack);
			//释放
			delete mychar2;
		}
	}
}

int main(void)
{
	char* str =(char *) "8+(3-1)*5";
	char* p = str;
	//创建一个栈
	LinkStack* stack = Init_LinkStack();
	while (*p != '\0')
	{
		if (IsNumber(*p))
		{
			NumberOperate(p);
		}
		p++;
		if (IsLeft(*p))//如果左括号，直接进栈
		{
			LeftOperate(stack, p);
		}
		if (IsRight(*p))
		{
			RightOperate(stack);
		}
		//如果是运算符号
		if (IsOperate(*p))
		{
			OperatorOperate(stack, p);
		}

	}
	//扫描完毕后判断栈里面有没有符号，如果有的话依次弹出
	while (Size_LinkStack(stack))
	{
		Mychar* mychar=(Mychar*)Top_LinkStack(stack);
		cout << *mychar->p;
		Pop_LinkStack(stack);
		delete (mychar);
	}

	return 0;
}
#endif