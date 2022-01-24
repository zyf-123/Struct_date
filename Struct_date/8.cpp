/*题目：海滩上有一堆桃子，五只猴子来分。第一只猴子把这堆桃子凭据分为五份，多了一个，这只猴子把多的一个扔入海中，
拿走了一份。第二只猴子把剩下的桃子又平均分成五份，又多了一个，它同样把多的一个扔入海中，拿走了一份，第三、第四、
第五只猴子都是这样做的，问海滩上原来最少有多少个桃子？*/
#if 0;
#include <iostream>
using namespace std;
int main(void)
{
	int num = 1;
	for (int i = 0; i < 5; i++)
	{
		num = 1 + num * 5;
	}
	cout << num;
	return 0;
}
#endif