#if 0;
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Process
{
public:
	string name;
	int type;
	int* allocation;
	int* need;
	bool is_Finish = false;

	Process(int type, string name);
	Process() { };


};
Process::Process(int type, string name) {
	Process::type = type;
	Process::name = name;
	allocation = new int[type];
	need = new int[type];
}

int* Available;
int n, m;
Process* processes;
vector<vector<Process>> safe;
vector<Process> lsafe;

void print_table() {
	printf("Process\t\tAllocatioin\tNeed\t\tAvailable\n");
	for (int i = 0; i < n; i++) {
		cout << processes[i].name << "\t\t";
		for (int j = 0; j < processes[i].type; j++) {
			int k = j + 1;
			if (k)
			{
				
				cout << processes[i].allocation[j] << "\t";
			}
		}
		for (int j = 0; j < processes[i].type; j++) {
			int k = j + 1;
			if (k)
			{
				cout << processes[i].need[j] << "\t";
			}
		}
		for (int j = 0; j < processes[i].type; j++) {
			int k = j + 1;
			if (k)
			{
				cout << Available[j] << "\t";
			}
		}
	}
}

bool resource_compare(int* compare) {
	for (int i = 0; i < m; i++) {
		if (compare[i] > Available[i]) return false;
	}
	return true;
}//大于可用的就返回false


void isSafe(int v) {
	// 递归出口
	// 如果v等于进程个数，打印，存储安全序列
	if (v == n) {
		safe.push_back(lsafe);
		return;
	}
	// 遍历寻找合适的开始进程
	for (int i = 0; i < n; i++) {
		// 判断进程是否处理完成
		if (!processes[i].is_Finish) {
			// 判断进程是否可以处理
			if (resource_compare(processes[i].need)) {
				// 暂时放入安全序列
				processes[i].is_Finish = true;
				lsafe.push_back(processes[i]);
				for (int j = 0; j < m; j++)
					Available[j] += processes[i].allocation[j];
				isSafe(v + 1); // 搜索下一个运行进程
				// 回溯
				lsafe.pop_back();
				for (int j = 0; j < m; j++)
					Available[j] -= processes[i].allocation[j];
				processes[i].is_Finish = 0;
			}
		}
	}
}

void printSafe() {
	for (vector<Process> lsafe : safe) {
		for (Process process : lsafe) {
			cout << process.name << " ";
		}
		cout << endl;
	}
}

int main() {
	cout << "请输入进程个数：";
	cin >> n;
	processes = new Process[n];
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个进程名：";
		string name;
		cin >> name;
		processes[i].name = name;
	}
	cout << "请输入资源种类数：";
	cin >> m;
	cout << "空格分隔两个数字" << endl;
	for (int i = 0; i < n; i++) {
		cout << "请输入" << processes[i].name << "的已分配资源数：";
		processes[i].type = m;
		processes[i].allocation = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> processes[i].allocation[j];
		}
	}
	// 读入还需资源数
	cout << "空格分隔两个数字" << endl;
	for (int i = 0; i < n; i++) {
		cout << "请输入" << processes[i].name << "的还需资源数：";
		processes[i].need = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> processes[i].need[j];
		}
	}

	// 读入空闲资源数
	cout << "请输入空闲资源数：";
	Available = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> Available[i];
	}

	cout << endl;
	print_table();
	isSafe(0);
	// 判断当前系统状态是否安全
	if (safe.size() == 0) {
		cout << "当前系统状态不安全！无任何安全序列，无法避免死锁！" << endl;
	}
	else {
		cout << "当前系统状态安全！" << endl << "安全序列有：" << endl;
		printSafe();
	}
}
#endif