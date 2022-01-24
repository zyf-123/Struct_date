#include<iostream>
using namespace std;
class Poccess
{
public:
	string name;
	int type;
	int* Need;
	int* Allocation;
	int* Max;
	Poccess(string name,int available);
	Poccess();
	~Poccess()
	{
		delete Need;
		delete Allocation;
		delete Max;
	}
};
bool compare(int * available,Poccess temp)
{
	for(int i=0;i<temp.type;i++)
	{
		if(temp.Need[i]>available[i])
		{
			return false;
		}
	}
	return true;
}
