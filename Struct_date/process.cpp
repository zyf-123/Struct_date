#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct jincheng_type {
	int pid;
	int youxian;
	int daxiao;
	int zhuangtai; //标志进程状态，0 为不在内存，1 为在内存，3 为挂起
	char info[10];
};
struct jincheng_type neicun[20];
int shumu = 0, guaqi = 0, pid, flag = 0;
void create() {
	if (shumu >= 20) printf("\n 内存已满，请先换出或杀死进程\n");
	else {
		for (int i = 0; i < 20; i++)
			//定位，找到可以还未创建的进程
			if (neicun[i].zhuangtai == 0) break;
		printf("\n 请输入新进程 pid\n");
		scanf("%d", &(neicun[i].pid));
		for (int j = 0; j < i; j++)
			if (neicun[i].pid == neicun[j].pid) {
				printf("\n 该进程已存在\n");
				return;
			}
		printf("\n 请输入新进程优先级\n");
		scanf("%d", &(neicun[i].youxian));
		printf("\n 请输入新进程大小\n");
		scanf("%d", &(neicun[i].daxiao));
		printf("\n 请输入新进程内容\n");
		scanf("%s", &(neicun[i].info));
		//创建进程，使标记位为 1
		neicun[i].zhuangtai = 1;
		shumu++;
	}
}
void run() {
	for (int i = 0; i < 20; i++) {
		if (neicun[i].zhuangtai == 1) {
			//输出运行进程的各个属性值
			printf("\n pid= %d", neicun[i].pid);
			printf(" youxian= %d", neicun[i].youxian);
			printf(" daxiao= %d", neicun[i].daxiao);
			printf(" zhuangtai= %d", neicun[i].zhuangtai);
			printf(" info= %s", neicun[i].info);
			flag = 1;
		}
	}
	if (!flag) printf("\n 当前没有运行进程\n");
}
void huanchu() {
	if (!shumu) {
		printf("当前没有运行进程\n");
		return;
	}
	printf("\n 输入换出进程的 ID 值");
	scanf("%d", &pid);
	for (int i = 0; i < 20; i++) {
		//定位，找到所要换出的进程，根据其状态做相应处理
		if (pid == neicun[i].pid) {
			if (neicun[i].zhuangtai == 1) {
				neicun[i].zhuangtai = 2;
				guaqi++;
				printf("\n 已经成功换出进程\n");
			}
			else if (neicun[i].zhuangtai == 0) printf("\n 要换出的进程不存在\n");
			else printf("\n 要换出的进程已被挂起\n");
			flag = 1;
			break;
		}
	}
	//找不到，则说明进程不存在
	if (flag == 0) printf("\n 要换出的进程不存在\n");
}
void kill() {
	if (!shumu) {
		printf("当前没有运行进程\n");
		return;
	}
	printf("\n 输入杀死进程的 ID 值");
	scanf("%d", &pid);
	for (int i = 0; i < 20; i++) {
		//定位，找到所要杀死的进程，根据其状态做相应处理
		if (pid == neicun[i].pid) {
			if (neicun[i].zhuangtai == 1) {
				neicun[i].zhuangtai = 0;
				shumu--;
				printf("\n 已成功杀死进程\n");
			}
			else if (neicun[i].zhuangtai == 0) printf("\n 要杀死的进程不存在\n");
			else printf("\n 要杀死的进程已被挂起\n");
			flag = 1;
			break;
		}
	}
	//找不到，则说明进程不存在
	if (!flag) printf("\n 要杀死的进程不存在\n");
}
void huanxing() {
	if (!shumu) {
		printf("当前没有运行进程\n");
		return;
	}
	if (!guaqi) {
		printf("\n 当前没有挂起进程\n");
		return;
	}
	printf("\n 输入 pid:\n");
	scanf("%d", &pid);
	for (int i = 0; i < 20; i++) {
		//定位，找到所要杀死的进程，根据其状态做相应处理
		if (pid == neicun[i].pid) {
			flag = false;
			if (neicun[i].zhuangtai == 2) {
				neicun[i].zhuangtai = 1;
				guaqi--;
				printf("\n 已经成功唤醒进程\n");
			}
			else if (neicun[i].zhuangtai == 0) printf("\n 要唤醒的进程不存在\n");
			else printf("\n 要唤醒的进程已被挂起\n");
			break;
		}
	}
	//找不到，则说明进程不存在
	if (flag) printf("\n 要唤醒的进程不存在\n");
}
void main() {
	int n = 1;
	int num;
	//一开始所有进程都不在内存中
	for (int i = 0; i < 20; i++)
		neicun[i].zhuangtai = 0;
	while (n) {
		printf("\n********************************************");
		printf("\n* 进程演示系统 *");
		printf("\n********************************************");
		printf("\n 1.创建新的进程 2.查看运行进程 ");
		printf("\n 3.换出某个进程 4.杀死运行进程 ");
		printf("\n 5.唤醒某个进程 6.退出系统 ");
		printf("\n********************************************");
		printf("\n 请选择(1～6)\n");
		scanf("%d", &num);
		switch (num) {
		case 1: create(); break;
		case 2: run(); break;
		case 3: huanchu(); break;
		case 4: kill(); break;
		case 5: huanxing(); break;
		case 6: exit(0);
		default: n = 0;
		}
		flag = 0;//恢复标记
	}
}