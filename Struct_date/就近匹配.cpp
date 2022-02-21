#include<iostream>
#pragma warning (disable:4996)
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0

using namespace std;
//用数组去模拟栈的顺序储存
#define MAX_SIZE 1024

typedef struct SEQSTACK
{
	void* data[MAX_SIZE];
	int size;

}Seqstack;
//初始化栈
Seqstack* Init_Seqstack();
//入栈操作
void Push_Seqstack(Seqstack* stack, void* data);
//返回栈顶元素
void* Top_Seqstack(Seqstack* stack);
//出栈
void Pop_Seqstack(Seqstack* stack);
//判断是否为空
int IsEmpty(Seqstack* stack);
//返回栈中元素的个数
int Size_SeqStack(Seqstack* stack);
//销毁
void FreeSeqStack(Seqstack* stack);
//清空
void Clear_SeqStack(Seqstack* stack);

//初始化栈
Seqstack* Init_Seqstack()
{
	Seqstack* stack = new Seqstack;
	stack->data[MAX_SIZE] = { NULL };
	stack->size = 0;
	return stack;
}
//入栈操作
void Push_Seqstack(Seqstack* stack, void* data)
{
	if (stack->size == MAX_SIZE || stack == NULL || data == NULL)
		return;
	stack->data[stack->size] = data;
	stack->size++;
}
//返回栈顶元素
void* Top_Seqstack(Seqstack* stack)
{
	if (stack == NULL || stack->size == 0)
		return NULL;
	return stack->data[stack->size - 1];
}
//出栈
void Pop_Seqstack(Seqstack* stack)
{
	if (stack->size == 0 || stack == NULL)
		return;
	stack->size--;
}
//判断是否为空
int IsEmpty(Seqstack* stack)
{
	if (stack->size == 0)
		return SEQSTACK_TRUE;
	return SEQSTACK_FALSE;
}
//返回栈中元素的个数
int Size_SeqStack(Seqstack* stack)
{
	return stack->size;
}
//销毁
void FreeSeqStack(Seqstack* stack)
{
	delete stack;
}
//清空
void Clear_SeqStack(Seqstack* stack)
{
	if (stack == NULL)
		return;
	stack->size = 0;
}
typedef struct Mychar
{
	char* Paddress;
	int index;
};
int IsLeft(char c)
{
	return c == '(';
}                        
int main(void)
{
	char* str = (char*)"#include<stdio.h> int main(){int a[4][4]; int (*p)[4];return 0;}";
	char* p = str;
	//扫描字符串，如果碰到左括号直接入栈，如果碰到右括号，直接从栈顶弹出括号，
	// 判断是否左括号，如果是，匹配成功，如果不是，匹配失败
	while (*p != '\0')
	{

	}
	//创建栈 
	Seqstack* stack = Init_Seqstack();
	

	return 0;
}