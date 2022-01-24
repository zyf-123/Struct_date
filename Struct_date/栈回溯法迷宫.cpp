#if 0;
#include<iostream>

using namespace std;
typedef struct stack
{
	int arr[16][2];//使用二维数组保存路径的位置
	int p;
}stacktype;//别名设置
int arr[4][4] = { {1,1,0,0},{0,1,1,1},{0,0,1,0},{0,0,1,1} };//迷宫的初始化，利用二维数组来模拟横纵坐标
void push(stack* s, int x,int y);//插入栈
void pop(stack* s,int x, int y);//出栈
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
	cout << "找到出口路径为:"<<endl;
	road(s);
	
	
	break;
	}
	}
	
	cout << "游戏结束";
	delete s;

	return 0;
}

void advance(stack* s,int x, int y)//判断右下左上有没有‘1’可走的路径有的话入栈保存路径
{
	 if (arr[x][y + 1] == 1)//右
	 {   
		push(s, x, ++y);

	 }
	else if (arr[x + 1][y] == 1)//下
	{
		push(s,++x,y);
		
	}
	else if (arr[x][y - 1] == 1)//左
	{
		push(s,x,--y);
		
	}
	else if (arr[x - 1][y] == 1 )//上
	{
		push(s,--x,y);
		
	}

	
	else//没有可行路径，则弹出栈空间后在上一个位置再次寻找
	{
		 pop(s, x, y);
	}
	
}

void push(stack* s, int x, int y)//入栈并保存x，y坐标，并且入栈后设置该为位置为0防止坐标出现重复入栈。
	{
		s->p++;
		s->arr[s->p][0] = x;
		s->arr[s->p][1] = y;
		arr[x][y] = 0;

	}

	void pop(stack * s,int x,int y)//出栈并且
	{
		

		s->p--;
			
	}
	int  getx(stack* s)//获取x坐标
	{
		
		return s->arr[s->p][0];
	}
	int  gety(stack* s)//获取y坐标
	{

		return s->arr[s->p][1];
	}

void road(stack* s)//反向打印路径
{
	while(s->p>-1)
	{

		cout << s->arr[s->p][0] << "," << s->arr[s->p][1] << endl;
		s->p--;
	}
}
#endif