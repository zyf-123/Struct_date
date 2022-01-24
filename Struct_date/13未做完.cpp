/*
密钥短语密码）
让我们选一个英文短语，称其为密钥字（key word）或密钥短语（key phrase），如HAPPY NEWYEAR，按顺序去掉重复字母和空格得HAPYNEWR。
将它依次写在明文字母表之下，而后再将明文字母表中未在短语中出现过的字母依次写在此短语之后，就可构造出一个代替表，如下所示：
明文：ABCDEFGHIJKLMNOPQRSTUVWXYZ
密文：HAPYNEWRBCDFGIJKLMOQSTUVXZ
请编写一个程序，可以通过用户输入密码（一个字符串）生成密码表（即上面的那个表），然后可以对用户输入的明文进行加密。
输入样例：
明文：I Love Huiwen
输出样例：
密文：ILoveHuiwnABCDFGJKMRSTWXYZ
*/
#include<iostream>
#include <vector>
#include<string>
using namespace std;
#if 0;
int main(void)
{
	string arr;
	cin >> arr;
	string str1;
 	for (int j = 0; j < arr.size();j++)//
	{
		for (int i=j+1;i<arr.size();i++)
		{
			if (arr[j] ==arr[i])
			{
				arr.erase(i,1);
			}
		}
	}
	
	cout << arr;
	return 0;
}	
#endif