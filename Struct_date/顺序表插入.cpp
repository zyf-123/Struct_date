#if 0;
#include <stdio.h>
#include<stdlib.h>
#define M 10
void insert(int* a, int i, int n)
{
	int temp;
	for (int j = n-1; j < M; j++)
	{
		temp = a[j];
		a[j] = i;
		i = temp;
	}
}
int main()
{
	int a[M] = { 1,2,3,4,6,7,8,9,10 };
	int i;
	for (i = 0; i < M; i++)
		printf("%d\t", a[i]); //排序前的数组 
	printf("\n");
	insert(a, 5,5);
	for (i = 0; i < M; i++)
		printf("%d\t", a[i]); //排序后的数组 
	return 0;
}
#endif