#if 0;
#include<iostream>

using namespace std;
typedef struct stack
{
	int arr[16][2];//ʹ�ö�ά���鱣��·����λ��
	int p;
}stacktype;//��������
int arr[4][4] = { {1,1,0,0},{0,1,1,1},{0,0,1,0},{0,0,1,1} };//�Թ��ĳ�ʼ�������ö�ά������ģ���������
void push(stack* s, int x,int y);//����ջ
void pop(stack* s,int x, int y);//��ջ
void advance(stack* s,int x, int y );
int  gety(stack* s);
int  getx(stack* s);
void road(stack* s);
int main()
{
	int x, y;
	x = y = 0;
	stack* s = new stack;
	s->p = -1;
	while (1)
	{
		advance(s, x, y);
		x = getx(s);
		y = gety(s);
	if (x == 3 && y == 3)
	{
	cout << "�ҵ�����·��Ϊ:"<<endl;
	road(s);
	
	
	break;
	}
	}
	
	cout << "��Ϸ����";
	delete s;

	return 0;
}

void advance(stack* s,int x, int y)//�ж�����������û�С�1�����ߵ�·���еĻ���ջ����·��
{
	 if (arr[x][y + 1] == 1)//��
	 {   
		push(s, x, ++y);

	 }
	else if (arr[x + 1][y] == 1)//��
	{
		push(s,++x,y);
		
	}
	else if (arr[x][y - 1] == 1)//��
	{
		push(s,x,--y);
		
	}
	else if (arr[x - 1][y] == 1 )//��
	{
		push(s,--x,y);
		
	}

	
	else//û�п���·�����򵯳�ջ�ռ������һ��λ���ٴ�Ѱ��
	{
		 pop(s, x, y);
	}
	
}

void push(stack* s, int x, int y)//��ջ������x��y���꣬������ջ�����ø�Ϊλ��Ϊ0��ֹ��������ظ���ջ��
	{
		s->p++;
		s->arr[s->p][0] = x;
		s->arr[s->p][1] = y;
		arr[x][y] = 0;

	}

	void pop(stack * s,int x,int y)//��ջ����
	{
		

		s->p--;
			
	}
	int  getx(stack* s)//��ȡx����
	{
		
		return s->arr[s->p][0];
	}
	int  gety(stack* s)//��ȡy����
	{

		return s->arr[s->p][1];
	}

void road(stack* s)//�����ӡ·��
{
	while(s->p>-1)
	{

		cout << s->arr[s->p][0] << "," << s->arr[s->p][1] << endl;
		s->p--;
	}
}
#endif