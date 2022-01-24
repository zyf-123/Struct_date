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
		int curx = x + ::move[0][i];//::ʹ�ñ�����Ĭ�ϵ�global namespace
		int cury = y + ::move[1][i];
		if (!vis[curx][cury] && !vis[6 - curx][6 - cury])//����ͶԳƵ�
		{
			vis[curx][cury] = 1;//����Ϊ����
			vis[6 - curx][6 - cury] = 1;//�ԳƵ� 
			dfs(curx, cury);//������������
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