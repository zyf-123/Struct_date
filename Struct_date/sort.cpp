#if 0;
#include<iostream>
#include<algorithm>
using namespace std;
//sort（三个参数，一个开始，一个结尾，另外一个排序的依据，或者说是方法。常见的又许多内置的排序方法sort(1, 10, greater<int>());<int>内部为一个泛型编程的变量）

bool cmp(int x,int y)//比较x,y的值并且返回bool类型的变量
{
	return x > y;
}
bool mod3(int x, int y)
{
	if (x % 3 != y % 3)
	{
		return x % 3 > y % 3;
	}
	else
	{
		return x > y;
	}
}
struct Student
{
	string name;
	int score[4];
};
bool name(Student x, Student y)//名字字典排序
{
	return x.name > y.name;
}
bool name(Student x, Student y)//按照成绩进行排序
{
	if (x.score[0] != y.score[0])
		return x.score[0] > y.score[0];
	if (x.score[1] != y.score[1])
		return x.score[1] > y.score[1];
	if (x.score[2] != y.score[2])
		return x.score[2] > y.score[2];
	return x.score[3] > y.score[3];
}
int num[105];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	sort(num, num + N, mod3);
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1)
		{
			cout << num[i] << " ";

		}
		else
		{
			cout << num[i] << endl;
		}
	}

	
	return 0;
}
#endif 