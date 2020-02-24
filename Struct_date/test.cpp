#if 0;
#include<iostream>

using namespace std;
typedef struct stack
{
	int arr[64][2];//使用二维数组保存路径的位置
	int p;
}stacktype;//别名设置
int arr[8][8] = { {1,1},{0,1,1},{1,1},{0,1,0,1},{0,1,1,1,1,1},{0,0,0,0,0,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1} };
void push(stack* s, int x, int y);//插入栈
void pop(stack* s, int x, int y);//出栈
void advance(stack* s, int x, int y);
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
		if (x == 7 && y == 7)
		{
			cout << "找到出口路径为:" << endl;
			road(s);


			break;
		}
	}

	cout << "游戏结束";
	delete s;

	return 0;
}

void advance(stack* s, int x, int y)
{
	if (arr[x][y + 1] == 1)//右
	{
		push(s, x, ++y);

	}
	else if (arr[x + 1][y] == 1)//下
	{
		push(s, ++x, y);

	}
	else if (arr[x][y - 1] == 1)//左
	{
		push(s, x, --y);

	}
	else if (arr[x - 1][y] == 1)//上
	{
		push(s, --x, y);

	}


	else
	{
		pop(s, x, y);
	}

}

void push(stack* s, int x, int y)
{
	s->p++;
	s->arr[s->p][0] = x;
	s->arr[s->p][1] = y;
	arr[x][y] = 0;

}

void pop(stack* s, int x, int y)
{
	

	s->p--;

}
int  getx(stack* s)
{

	return s->arr[s->p][0];
}
int  gety(stack* s)
{

	return s->arr[s->p][1];
}

void road(stack* s)
{
	while (s->p > -1)
	{

		cout << s->arr[s->p][0] << "," << s->arr[s->p][1] << endl;
		s->p--;
	}
}


#endif