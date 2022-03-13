#include<stdio.h>
int fun(int x)
{
	if (x > 0)
	{
		return x * fun(x - 1);
	}
	else
		return 1;
}
int main(void)
{
	int i=fun(5);
	printf("%d", i);
	return 0;
}