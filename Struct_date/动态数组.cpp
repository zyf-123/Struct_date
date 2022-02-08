#if 0;
#include<iostream>
#include<iomanip>
using namespace std;
//��̬�����ڴ棬���ԣ�����ŵ��ڴ�ŵ�����
//capacity ��������ÿ�ζ���һ��ռ䣬�������Բ���ÿ�ζ�ȥ����һ���µ��ڴ�ռ�
//�����ڴ� �������ݵ��µ��ڴ��У��ͷŹ�ȥ�ɵĿռ�
//size������¼��ǰ�����о����Ԫ�ظ���
typedef  struct DYNAMICARRAY
{
	int* pAdder;//������ݵĵ�ַ
	int size;//��ǰ�ж��ٸ�Ԫ��
	int capacity;//���������������
	
}Dynamic_Array;

//дһϵ�нṹ������ĺ���
Dynamic_Array* Init_Dynamic_Array();//��ʼ��
void Push_Back_Array(Dynamic_Array* arr, int value);//����
void Remove_Arrayy_Bypos(Dynamic_Array* arr, int pos);//����λ�ý���ɾ��
void Remove_Arrayy_Byvalue(Dynamic_Array* arr, int value);//������ֵ����ɾ��
void FreeSpace_Array(Dynamic_Array * arr);//�ͷŶ�̬������ڴ�
int Find_Array(Dynamic_Array* arr, int value);//������ֵ���в���
void Clear_Array(Dynamic_Array* arr);//�������
int  Capacity_Array(Dynamic_Array* arr);//��ȡ��̬�����������
int  Size_Array(Dynamic_Array* arr);//��ȡ��̬����ĵ�ǰ������
int At_Array(Dynamic_Array* arr, int pos);//����λ�û��λ���ϵ�Ԫ�ص�ֵ
void Print_Array(Dynamic_Array* arr);//��ӡ���е�����


Dynamic_Array* Init_Dynamic_Array()
{
	Dynamic_Array* myArray = new Dynamic_Array;//�����ڴ�
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAdder = new int[myArray->capacity];//�ȳ�ʼ������20��int��λ
	return myArray;
}

void Print_Array(Dynamic_Array* arr)//��ӡ���е�����
{
	if (arr == NULL)
		return;
	for (int i = 0; i < arr->size; i++)
	{
		cout<<setw(3) << arr->pAdder[i];
	}
	cout << endl;
}

void Clear_Array(Dynamic_Array* arr)//�������
{
	if (arr == NULL)
		return;
	arr->size = 0;
}

int  Size_Array(Dynamic_Array* arr)//��ȡ��̬����ĵ�ǰ������
{
	if (arr == NULL)
		return -1;
	return arr->size;
}

int  Capacity_Array(Dynamic_Array* arr)//��ȡ��̬�����������
{
	if (arr == NULL)
		return -1;
	return arr->capacity;
}

int At_Array(Dynamic_Array* arr, int pos)//����λ�û��λ���ϵ�Ԫ�ص�ֵ
{

	if (arr == NULL)
		return -1;
	return arr->pAdder[pos];
}
void Push_Back_Array(Dynamic_Array* arr, int value)//����
{
	if (arr == NULL)
		return;
	if (arr->size == arr->capacity)//�жϿռ��Ƿ��㹻
	{
		//��������һ���ڴ�ռ� �¿ռ�����Ϊ�ɿռ������
		int* NewSpace = new int[arr->capacity * 2];
		//�������ݵ��µĿռ���
		memcpy(NewSpace, arr->pAdder, arr->capacity * sizeof(int));//���������ֱ����¿ռ䣬�ɿռ䣬�Լ�����������
		//�ͷžɿռ�
		delete arr->pAdder;
		//��������
		arr->capacity = arr->capacity * 2;
		arr->pAdder = NewSpace;

	}
	arr->pAdder[arr->size] = value;
	arr->size++;
}

void Remove_Arrayy_Bypos(Dynamic_Array* arr, int pos)//����λ�ý���ɾ��
{
	if (arr == NULL)
		return;
	if (pos < 0 || pos >= arr->size)
	{
		return;
	}
	//ɾ��Ԫ��
	for (int i = pos; i < arr->size; i++)//ɾ��posλ�õ�Ԫ�� pos����İ�����ǰ�ƶ�
	{
		arr->pAdder[i] = arr->pAdder[i + 1];
	}
	arr -> size--;
}

void Remove_Arrayy_Byvalue(Dynamic_Array* arr, int value)//������ֵ����ɾ��
{
	if (arr == NULL)
	{
		return;
	}
		Remove_Arrayy_Bypos(arr,(Find_Array(arr, value)));//����д�õĺ������ҵ���ֵ��λ�ã�Ȼ�����λ�ý���ɾ����
	
}
void FreeSpace_Array(Dynamic_Array* arr)//�ͷŶ�̬������ڴ�
{
	if (arr == NULL)
		return;
	if (arr->pAdder != NULL)
	{
		delete arr->pAdder;
	}
	delete arr;
}
int Find_Array(Dynamic_Array* arr, int value)//������ֵ���в���
{
	//��ֵ��λ��
	int pos = -1;
	for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAdder[i] == value)
		{
			pos = i;
			break;//ֻɾ����һ�γ��ֵ�λ��
		}
	}
	return pos;
}
int main(void)
{
	//����һ�²���
	//��ʼ��һ����̬����
	Dynamic_Array* myArray = Init_Dynamic_Array();
	cout << "��ǰ������" << myArray->capacity;
	//��������
	for (int i = 0; i < 30; i++)
	{
		Push_Back_Array(myArray, i);
	}
	//��ӡ
	Print_Array(myArray);
	//ɾ������һ��Ԫ��
	Remove_Arrayy_Byvalue(myArray, 5);
	Print_Array(myArray);


	return 0;
}
#endif