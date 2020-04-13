#if 0
#include<iostream>
#include<string>
using namespace std;
void get_next(string  T, int next[])
{
	int j = 1, k = 0;
	next[1] = 0;
	while (j < T.length())
	{
		if (k == 0 || T[j] == T[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}

int main(void)
{
	string t = "#abaabcac";
	int next[9];
	get_next(t, next);
}
#endif
