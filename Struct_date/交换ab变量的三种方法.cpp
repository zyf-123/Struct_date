#if  0;
#include<iostream>

using namespace std;
void sw(int* a, int* b)
{
	int* temp;
	temp = &*a;
	a = &*b;
	b = &*temp;
}
/*void sw(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}*/
void swap1(int* a, int* b)//不适用第三个变量 相互加减的方法
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void swap2(int* a, int* b)//不适用三方变量 直接在过程中赋值
{
	*b = (*a + *b) - (*a = *b);
}
void swap3(int* a, int* b) //异或中某些数据可以翻转，任意一个数字与任意一个给定的值连续异或俩次，值不变。  不建议在实际使用中采用这样的写法。这种奇技淫巧虽然看起来十分巧妙，
																											//但这样并不见得能够比朴素的交换来的更快。而且这种方法存在一个缺陷：
																											//如果 a 和 b 引用的是同一个变量的话，使用这种方法会使得这个变量变为0。
{
	//异或满足交换律和结合律
	//x^ x == 0
	//x ^ 0 == x

	*a = *a  ^ *b;//a=1010 b=1100  结果 a=0110 b=1100
	*b = *a ^ *b; //a=0110 b=1100  结果 a=0110 b=1010   b=a^b^b=a^0=a;
	*a = *a ^ *b;// b=1010 a=0110 结果 a=1100  b=1010   a=a^b^a=a^a^b=b;
}
int main(void)
{
	int a, b;
	a = 10, b = 12;
	swap3(&a, &b);
	cout << a << "    " << b << endl;
	return 0;

}
#endif