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
void swap1(int* a, int* b)//�����õ��������� �໥�Ӽ��ķ���
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void swap2(int* a, int* b)//�������������� ֱ���ڹ����и�ֵ
{
	*b = (*a + *b) - (*a = *b);
}
void swap3(int* a, int* b) //�����ĳЩ���ݿ��Է�ת������һ������������һ��������ֵ����������Σ�ֵ���䡣  ��������ʵ��ʹ���в���������д���������漼������Ȼ������ʮ�����
																											//���������������ܹ������صĽ������ĸ��졣�������ַ�������һ��ȱ�ݣ�
																											//��� a �� b ���õ���ͬһ�������Ļ���ʹ�����ַ�����ʹ�����������Ϊ0��
{
	//������㽻���ɺͽ����
	//x^ x == 0
	//x ^ 0 == x

	*a = *a  ^ *b;//a=1010 b=1100  ��� a=0110 b=1100
	*b = *a ^ *b; //a=0110 b=1100  ��� a=0110 b=1010   b=a^b^b=a^0=a;
	*a = *a ^ *b;// b=1010 a=0110 ��� a=1100  b=1010   a=a^b^a=a^a^b=b;
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