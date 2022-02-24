#if 0;
/*��׺���ʽ���ǳ�������ѧ���ʽ�����ǰ�������ŵ����ֵĺ������ӷ��ϼ����������
����5+4= ����һ����׺���ʽ �����ĺ�׺���ʽӦ���� 5 4+    1+2*3 ��� 1 2 3 * +
��׺ת��׺���㷨
��������ֱ����� �������ţ���������ջ�������������ŵĻ�������ջ�����Ž������ȼ��Ƚϣ�
���ջ���������ȼ��ͣ���˷�����ջ�����ջ���������ȼ��ߣ���ջ���ķ��ŵ��������Ȼ��÷�����ջ
������:��ջ���ķ��ŵ����������ֱ��ƥ�䵽������*/
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


//�ж��ǲ���������
int IsLeft(char c)
{
	return c == '(';
}
//�ж��ǲ����ұ�����
int IsRight(char c)
{
	return c == ')';
}
//�ж��ǲ����������
int IsOperate(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
//������������ŵ����ȼ�
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
//���ֵĲ���
void NumberOperate(char* p)
{
	cout << *p;
}
//����Mychar
Mychar* CreatMychar(char* p)
{
	Mychar* mychar = new Mychar;
	mychar->p = p;
	return mychar;
}
//�����ŵĲ���
void LeftOperate(LinkStack* stack, char* p)
{
	Mychar* mychar= CreatMychar(p);
	Push_LinkStack(stack,(LinkNode*)mychar);
}
//�����Ų���
void RightOperate(LinkStack* stack)
{
	while (Size_LinkStack(stack) > 0)
	{
		Mychar* mychar = (Mychar*)Top_LinkStack(stack);
		//���ƥ�䵽�����ţ�Ӧ�õ���
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
//������ŵĲ���
void OperatorOperate(LinkStack* stack, char* p)
{
	Mychar* mychar= (Mychar*)Top_LinkStack(stack);
	//���ջ�������޼����ڵ�ǰ�ַ������ȼ���ֱ����ջ
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
	//���ջ�������ȼ�����
	else
	{
		while (Size_LinkStack(stack) > 0)
		{
			Mychar* mychar2 =(Mychar*)Top_LinkStack(stack);

			//������ȼ��� ��ǰ������ջ
			if (GetPriority(*mychar2->p) < GetPriority(*p))
			{
				Push_LinkStack(stack, (LinkNode*)CreatMychar(p));
				break;
			}
			//���
			cout << (*mychar2->p);
			//����
			Pop_LinkStack(stack);
			//�ͷ�
			delete mychar2;
		}
	}
}

int main(void)
{
	char* str =(char *) "8+(3-1)*5";
	char* p = str;
	//����һ��ջ
	LinkStack* stack = Init_LinkStack();
	while (*p != '\0')
	{
		if (IsNumber(*p))
		{
			NumberOperate(p);
		}
		p++;
		if (IsLeft(*p))//��������ţ�ֱ�ӽ�ջ
		{
			LeftOperate(stack, p);
		}
		if (IsRight(*p))
		{
			RightOperate(stack);
		}
		//������������
		if (IsOperate(*p))
		{
			OperatorOperate(stack, p);
		}

	}
	//ɨ����Ϻ��ж�ջ������û�з��ţ�����еĻ����ε���
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