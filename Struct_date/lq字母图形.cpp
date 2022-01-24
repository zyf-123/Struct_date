#if 0;
#include <iostream>
using namespace std;
int main(void)
{
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		int temp = i;
		for (int j = 0; j < m; j++)
		{
			
			if (temp > 0&&flag==0)
			{
				cout << char(65+temp)  ;
				temp--;
			}
			else if(temp==0&&flag==0)
			{
				cout << char(65 + temp) ;
				temp++;
				flag = 1;

			}
			else
			{
				cout << char(65 + temp);
				temp++;
			}
				
		}
		cout << endl;
	}

	return 0;

}
#endif