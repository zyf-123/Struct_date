#if 0;
#include<iostream>
using namespace std;
int main(void)
{
	long long num, yushu;
	cin >> num;
	string arr= "0123456789ABCDEF";
	string sum;
	if (num == 0)
		cout << 0;
	else
	while (num  != 0)
	{
		yushu = num % 16;
		sum = arr[yushu] + sum;
		num = num / 16;
	
	
	}

		cout << sum;
	return 0;
}

/*#include <iostream>
using namespace std;
int main(void)
{
	long long n, x;
	string s;
	string t = "0123456789ABCDEF";

		cin >> n;

		while (n != 0) {
			x = n % 16;
			// �� n % 16 ת��Ϊ�ַ�������� s 
			s = t[x] + s;
			n = n / 16;
		}

		if (s == "") {
			cout << 0;
		}
		else {
			cout << s;
		}
	}
	*/
#endif 