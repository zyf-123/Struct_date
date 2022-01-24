#if 0;
#include<iostream> 
using namespace std;
int ans = 0;
int move[][4] = { {-1,1,0,0},{0,0,-1,1} };
int vis[7][7] = { 0 };

void dfs(int x, int y)
{

	if (x <= 0 || x >= 6 || y <= 0 || y >= 6)
	{
		ans++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int curx = x + ::move[0][i];//::使用本程序默认的global namespace
		int cury = y + ::move[1][i];
		if (!vis[curx][cury] && !vis[6 - curx][6 - cury])//本点和对称点
		{
			vis[curx][cury] = 1;//设置为可以
			vis[6 - curx][6 - cury] = 1;//对称点 
			dfs(curx, cury);//继续搜索下面
			vis[curx][cury] = 0;
			vis[6 - curx][6 - cury] = 0;
		}
	}
}


int main()
{
	vis[3][3] = 1;
	dfs(3, 3);
	cout << ans / 4 << endl;
	return 0;
}
#endif