#include<iostream>
#include<string>
using namespace std;
int cp(string s, string t)
{
	int i;
	for (i = 0; s[i] == t[i], i < s.length(), i < t.length(); i++);
	if (i == s.length() &&i== t.length())
		return 0;
	return 1;
}
int main(void)
{
	string s = "1234";
	string t = "1234";
	cout << cp(s, t);
}
