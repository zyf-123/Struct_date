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
}//���ڿ��õľͷ���false


void isSafe(int v) {
	// �ݹ����
	// ���v���ڽ��̸�������ӡ���洢��ȫ����
	if (v == n) {
		safe.push_back(lsafe);
		return;
	}
	// ����Ѱ�Һ��ʵĿ�ʼ����
	for (int i = 0; i < n; i++) {
		// �жϽ����Ƿ������
		if (!processes[i].is_Finish) {
			// �жϽ����Ƿ���Դ���
			if (resource_compare(processes[i].need)) {
				// ��ʱ���밲ȫ����
				processes[i].is_Finish = true;
				lsafe.push_back(processes[i]);
				for (int j = 0; j < m; j++)
					Available[j] += processes[i].allocation[j];
				isSafe(v + 1); // ������һ�����н���
				// ����
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
	cout << "��������̸�����";
	cin >> n;
	processes = new Process[n];
	for (int i = 0; i < n; i++) {
		cout << "�������" << i + 1 << "����������";
		string name;
		cin >> name;
		processes[i].name = name;
	}
	cout << "��������Դ��������";
	cin >> m;
	cout << "�ո�ָ���������" << endl;
	for (int i = 0; i < n; i++) {
		cout << "������" << processes[i].name << "���ѷ�����Դ����";
		processes[i].type = m;
		processes[i].allocation = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> processes[i].allocation[j];
		}
	}
	// ���뻹����Դ��
	cout << "�ո�ָ���������" << endl;
	for (int i = 0; i < n; i++) {
		cout << "������" << processes[i].name << "�Ļ�����Դ����";
		processes[i].need = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> processes[i].need[j];
		}
	}

	// ���������Դ��
	cout << "�����������Դ����";
	Available = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> Available[i];
	}

	cout << endl;
	print_table();
	isSafe(0);
	// �жϵ�ǰϵͳ״̬�Ƿ�ȫ
	if (safe.size() == 0) {
		cout << "��ǰϵͳ״̬����ȫ�����κΰ�ȫ���У��޷�����������" << endl;
	}
	else {
		cout << "��ǰϵͳ״̬��ȫ��" << endl << "��ȫ�����У�" << endl;
		printSafe();
	}
}
#endif