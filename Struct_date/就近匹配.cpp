#if 0;
#include<iostream>
#pragma warning (disable:4996)
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0

using namespace std;
//������ȥģ��ջ��˳�򴢴�
#define MAX_SIZE 1024

typedef struct SEQSTACK
{
	void* data[MAX_SIZE];
	int size;

}Seqstack;
//��ʼ��ջ
Seqstack* Init_Seqstack();
//��ջ����
void Push_Seqstack(Seqstack* stack, void* data);
//����ջ��Ԫ��
void* Top_Seqstack(Seqstack* stack);
//��ջ
void Pop_Seqstack(Seqstack* stack);
//�ж��Ƿ�Ϊ��
int IsEmpty(Seqstack* stack);
//����ջ��Ԫ�صĸ���
int Size_SeqStack(Seqstack* stack);
//����
void FreeSeqStack(Seqstack* stack);
//���
void Clear_SeqStack(Seqstack* stack);

//��ʼ��ջ
Seqstack* Init_Seqstack()
{
	Seqstack* stack = new Seqstack;
	stack->data[MAX_SIZE] = { NULL };
	stack->size = 0;
	return stack;
}
//��ջ����
void Push_Seqstack(Seqstack* stack, void* data)
{
	if (stack->size == MAX_SIZE || stack == NULL || data == NULL)
		return;
	stack->data[stack->size] = data;
	stack->size++;
}
//����ջ��Ԫ��
void* Top_Seqstack(Seqstack* stack)
{
	if (stack == NULL || stack->size == 0)
		return NULL;
	return stack->data[stack->size - 1];
}
//��ջ
void Pop_Seqstack(Seqstack* stack)
{
	if (stack->size == 0 || stack == NULL)
		return;
	stack->size--;
}
//�ж��Ƿ�Ϊ��
int IsEmpty(Seqstack* stack)
{
	if (stack->size == 0)
		return SEQSTACK_TRUE;
	return SEQSTACK_FALSE;
}
//����ջ��Ԫ�صĸ���
int Size_SeqStack(Seqstack* stack)
{
	return stack->size;
}
//����
void FreeSeqStack(Seqstack* stack)
{
	delete stack;
}
//���
void Clear_SeqStack(Seqstack* stack)
{
	if (stack == NULL)
		return;
	stack->size = 0;
}
typedef struct Mychar
{
	char* Paddress;//�ַ�
	int index;//��ʶ��λ��
};
int IsLeft(char c)
{
	return c == '(';
}    
int IsRight(char c)
{
	return c == ')';
}
Mychar* CreatMychar(char* p,int index)
{
	Mychar* mychar = new Mychar;
	mychar->Paddress = p;
	mychar->index = index;
	return mychar;
}
void ShowError(char* str, int pos)
{
	cout << str << endl;
	for (int i = 0; i < pos; i++)
	{
		cout << " ";
	}
	cout << "A";
}
int main(void)
{
	char* str = (char*)"#incl(ude<stdio.h> int main(){int a[4][4]; int (*p)[4];return 0;}";
	char* p = str;
	int index = 0;
	//����ջ 
	Seqstack* stack = Init_Seqstack();
	//ɨ���ַ������������������ֱ����ջ��������������ţ�ֱ�Ӵ�ջ���������ţ�
	// �ж��Ƿ������ţ�����ǣ�ƥ��ɹ���������ǣ�ƥ��ʧ��
	while (*p != '\0')
	{
		//����������ţ�ֱ�ӽ�ջ
		if (IsLeft(*p))
		{
			Push_Seqstack(stack, CreatMychar(p,index));
		}
		//����������ţ���ջ������Ԫ�أ��ж��Ƿ�������
		if (IsRight(*p))
		{
			if (Size_SeqStack(stack) > 0)
			{
				Mychar* mychar = (Mychar*)Top_Seqstack(stack);
				if (IsLeft(*mychar->Paddress))
					Pop_Seqstack(stack);
				delete mychar;
			}
			else
			{
				cout << "�ô�������û��ƥ�䵽������" << endl;
				ShowError(str, index);
				break;
			}
		}
		p++;
		index++;
	}
	while (Size_SeqStack(stack) > 0)
	{
		Mychar* mychar=(Mychar*)Top_Seqstack(stack);
		cout << "������û��ƥ��������ţ�" << endl;
		ShowError(str, mychar->index);
		Pop_Seqstack(stack);
		delete mychar;

	}

	

	return 0;
}
#endif