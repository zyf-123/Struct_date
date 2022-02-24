#if 0;
/*���ں�׺���ʽ�ļ�������
��������ȫ����ջ
���ڷ��ţ���ջ�е����Ҳ�������Ȼ���ջ�е���������������ݷ��Ž�����Ӧ�ļ��㣬Ȼ���������ڴ�ѹ��ջ��
ֱ��ʣ��һ��ֵ*/
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


//��ʼ������
LinkStack* Init_LinkStack();
//��ջ
void Push_LinkStack(LinkStack* stack, LinkNode* data);
//��ջ
void Pop_LinkStack(LinkStack* stack);
//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack);
//����ջԪ�صĸ���
int  Size_LinkStack(LinkStack* stack);
//���ջ
void Clear_LinkStack(LinkStack* stack);
//����ջ
void FreeSpace_LinkStack(LinkStack* stack);

//��ʼ������
LinkStack* Init_LinkStack()
{
	LinkStack* stack = new LinkStack;
	stack->head.next = NULL;
	stack->size = 0;
	return stack;
}
//��ջ
void Push_LinkStack(LinkStack* stack, LinkNode* data)
{
	if (stack == NULL || data == NULL)
		return;
	data->next = stack->head.next;
	stack->head.next = data;
	stack->size++;
}
//��ջ
void Pop_LinkStack(LinkStack* stack)
{
	if (stack == NULL || stack->size == 0)
		return;
	//��һ����Ч�ڵ�
	LinkNode* Pnext = stack->head.next;
	stack->head.next = Pnext->next;
	stack->size--;
}
//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack)
{
	if (stack == NULL || stack->size == 0)
		return NULL;
	//��һ����Ч�ڵ�
	LinkNode* Pnext = stack->head.next;
	return Pnext;
}
//����ջԪ�صĸ���
int  Size_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
		return -1;
	return stack->size;
}
//���ջ
void Clear_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
		return;
	stack->head.next = NULL;
	stack->size = 0;
}
//����ջ
void FreeSpace_LinkStack(LinkStack* stack)
{
	delete(stack);
}
//�ж��Ƿ�������
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
	//��׺���ʽ
	char* str = (char *)"831-5*+";
	char* p = str;
	//����ջ
	LinkStack* stack = Init_LinkStack();
	while (*p != '\0')
	{
		//���������ֱ����ջ
		if (IsNumber(*p))
		{
			MyNum* num = new MyNum;
			num->num = *p-'0';//ANSCII
			Push_LinkStack(stack, (LinkNode*)num);
		}
		else
		{
			//�ȴ�ջ�е����ұ߲�����
			MyNum* right = (MyNum*)Top_LinkStack(stack);
			int right_num = right->num;
			Pop_LinkStack(stack);
			delete right;
			//Ȼ��ȡ���Ҳ�����
			MyNum* left = (MyNum*)Top_LinkStack(stack);
			int left_num = left->num;
			Pop_LinkStack(stack);
			delete left;
			int ret = Caculate(*p,left_num, right_num);
			//�����ջ
			MyNum* num = new MyNum;
			num->num = ret;
			Push_LinkStack(stack, (LinkNode*)num);

		}
		p++;
	}
	if (Size_LinkStack(stack) == 1)
	{
		MyNum* mynum = (MyNum*)Top_LinkStack(stack);
		cout << "��������:" << mynum->num << endl;
		Pop_LinkStack(stack);
		delete mynum;
	}
	//�ͷ�ջ
	FreeSpace_LinkStack(stack);
	return 0;
}
#endif