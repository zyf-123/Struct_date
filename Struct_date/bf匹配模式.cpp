#if 0
#include<iostream>
using namespace std;
int index(string &  s, int pos, string & t)
{
	int i = pos, j = 1;
	while (i <= s.length() && j <= t.length())
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 1;
		}
	}
	if (j > t.length())
	{
		return i - t.length();//也可以写成i-j+1;
	}
	else
		return 0;
}
#endif