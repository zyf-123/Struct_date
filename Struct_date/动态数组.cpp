#if 0;
#include<iostream>
#include<iomanip>
using namespace std;
//动态增长内存，策略，将存放的内存放到堆上
//capacity （容量）每次多上一点空间，这样可以不用每次都去建立一个新的内存空间
//申请内存 拷贝数据到新的内存中，释放过去旧的空间
//size用来记录当前数组中具体的元素个数
typedef  struct DYNAMICARRAY
{
	int* pAdder;//存放数据的地址
	int size;//当前有多少个元素
	int capacity;//容器的最大容纳量
	
}Dynamic_Array;

//写一系列结构体操作的函数
Dynamic_Array* Init_Dynamic_Array();//初始化
void Push_Back_Array(Dynamic_Array* arr, int value);//插入
void Remove_Arrayy_Bypos(Dynamic_Array* arr, int pos);//根据位置进行删除
void Remove_Arrayy_Byvalue(Dynamic_Array* arr, int value);//根据数值进行删除
void FreeSpace_Array(Dynamic_Array * arr);//释放动态数组的内存
int Find_Array(Dynamic_Array* arr, int value);//根据数值进行查找
void Clear_Array(Dynamic_Array* arr);//清空数组
int  Capacity_Array(Dynamic_Array* arr);//获取动态数组的容量；
int  Size_Array(Dynamic_Array* arr);//获取动态数组的当前容量；
int At_Array(Dynamic_Array* arr, int pos);//根据位置获得位置上的元素的值
void Print_Array(Dynamic_Array* arr);//打印其中的内容


Dynamic_Array* Init_Dynamic_Array()
{
	Dynamic_Array* myArray = new Dynamic_Array;//申请内存
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAdder = new int[myArray->capacity];//先初始化申请20个int单位
	return myArray;
}

void Print_Array(Dynamic_Array* arr)//打印其中的内容
{
	if (arr == NULL)
		return;
	for (int i = 0; i < arr->size; i++)
	{
		cout<<setw(3) << arr->pAdder[i];
	}
	cout << endl;
}

void Clear_Array(Dynamic_Array* arr)//清空数组
{
	if (arr == NULL)
		return;
	arr->size = 0;
}

int  Size_Array(Dynamic_Array* arr)//获取动态数组的当前容量；
{
	if (arr == NULL)
		return -1;
	return arr->size;
}

int  Capacity_Array(Dynamic_Array* arr)//获取动态数组的容量；
{
	if (arr == NULL)
		return -1;
	return arr->capacity;
}

int At_Array(Dynamic_Array* arr, int pos)//根据位置获得位置上的元素的值
{

	if (arr == NULL)
		return -1;
	return arr->pAdder[pos];
}
void Push_Back_Array(Dynamic_Array* arr, int value)//插入
{
	if (arr == NULL)
		return;
	if (arr->size == arr->capacity)//判断空间是否足够
	{
		//申请更大的一块内存空间 新空间设置为旧空间的俩倍
		int* NewSpace = new int[arr->capacity * 2];
		//拷贝数据到新的空间中
		memcpy(NewSpace, arr->pAdder, arr->capacity * sizeof(int));//三个参数分别是新空间，旧空间，以及拷贝的容量
		//释放旧空间
		delete arr->pAdder;
		//更新容量
		arr->capacity = arr->capacity * 2;
		arr->pAdder = NewSpace;

	}
	arr->pAdder[arr->size] = value;
	arr->size++;
}

void Remove_Arrayy_Bypos(Dynamic_Array* arr, int pos)//根据位置进行删除
{
	if (arr == NULL)
		return;
	if (pos < 0 || pos >= arr->size)
	{
		return;
	}
	//删除元素
	for (int i = pos; i < arr->size; i++)//删除pos位置的元素 pos后面的挨个往前移动
	{
		arr->pAdder[i] = arr->pAdder[i + 1];
	}
	arr -> size--;
}

void Remove_Arrayy_Byvalue(Dynamic_Array* arr, int value)//根据数值进行删除
{
	if (arr == NULL)
	{
		return;
	}
		Remove_Arrayy_Bypos(arr,(Find_Array(arr, value)));//调用写好的函数，找到数值的位置，然后根据位置进行删除；
	
}
void FreeSpace_Array(Dynamic_Array* arr)//释放动态数组的内存
{
	if (arr == NULL)
		return;
	if (arr->pAdder != NULL)
	{
		delete arr->pAdder;
	}
	delete arr;
}
int Find_Array(Dynamic_Array* arr, int value)//根据数值进行查找
{
	//找值的位置
	int pos = -1;
	for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAdder[i] == value)
		{
			pos = i;
			break;//只删除第一次出现的位置
		}
	}
	return pos;
}
int main(void)
{
	//进行一下测试
	//初始化一个动态数组
	Dynamic_Array* myArray = Init_Dynamic_Array();
	cout << "当前的容量" << myArray->capacity;
	//插入数组
	for (int i = 0; i < 30; i++)
	{
		Push_Back_Array(myArray, i);
	}
	//打印
	Print_Array(myArray);
	//删除其中一个元素
	Remove_Arrayy_Byvalue(myArray, 5);
	Print_Array(myArray);


	return 0;
}
#endif