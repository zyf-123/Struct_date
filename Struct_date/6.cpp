//题目：两个乒乓球队进行比赛，各出三人。甲队为a, b, c三人，乙队为x, y, z三人。已抽签决定比赛名单。有人向队员打听比赛的名单。a说他不和x比，c说他不和x, z比，请编程序找出三队赛手的名单。
#if 0;
#include <iostream>
using namespace std;
int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int  j = 0; j < 3; j++)
		{
			if (i != j)
			{
				for (int  k = 0; k < 3; k++)
				{
					if (k != i && k != j)
					{
						if (i != 0 && k != 0 && k != 2)
						{
							cout << "a和" << i << "b" << j << "c" << k;
						}
					}
				}
			}
		}
	}
	return 0;
}
#endif