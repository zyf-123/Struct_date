/*
��Կ�������룩
������ѡһ��Ӣ�Ķ������Ϊ��Կ�֣�key word������Կ���key phrase������HAPPY NEWYEAR����˳��ȥ���ظ���ĸ�Ϳո��HAPYNEWR��
��������д��������ĸ��֮�£������ٽ�������ĸ����δ�ڶ����г��ֹ�����ĸ����д�ڴ˶���֮�󣬾Ϳɹ����һ�������������ʾ��
���ģ�ABCDEFGHIJKLMNOPQRSTUVWXYZ
���ģ�HAPYNEWRBCDFGIJKLMOQSTUVXZ
���дһ�����򣬿���ͨ���û��������루һ���ַ����������������������Ǹ�����Ȼ����Զ��û���������Ľ��м��ܡ�
����������
���ģ�I Love Huiwen
���������
���ģ�ILoveHuiwnABCDFGJKMRSTWXYZ
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