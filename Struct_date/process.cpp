#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct jincheng_type {
	int pid;
	int youxian;
	int daxiao;
	int zhuangtai; //��־����״̬��0 Ϊ�����ڴ棬1 Ϊ���ڴ棬3 Ϊ����
	char info[10];
};
struct jincheng_type neicun[20];
int shumu = 0, guaqi = 0, pid, flag = 0;
void create() {
	if (shumu >= 20) printf("\n �ڴ����������Ȼ�����ɱ������\n");
	else {
		for (int i = 0; i < 20; i++)
			//��λ���ҵ����Ի�δ�����Ľ���
			if (neicun[i].zhuangtai == 0) break;
		printf("\n �������½��� pid\n");
		scanf("%d", &(neicun[i].pid));
		for (int j = 0; j < i; j++)
			if (neicun[i].pid == neicun[j].pid) {
				printf("\n �ý����Ѵ���\n");
				return;
			}
		printf("\n �������½������ȼ�\n");
		scanf("%d", &(neicun[i].youxian));
		printf("\n �������½��̴�С\n");
		scanf("%d", &(neicun[i].daxiao));
		printf("\n �������½�������\n");
		scanf("%s", &(neicun[i].info));
		//�������̣�ʹ���λΪ 1
		neicun[i].zhuangtai = 1;
		shumu++;
	}
}
void run() {
	for (int i = 0; i < 20; i++) {
		if (neicun[i].zhuangtai == 1) {
			//������н��̵ĸ�������ֵ
			printf("\n pid= %d", neicun[i].pid);
			printf(" youxian= %d", neicun[i].youxian);
			printf(" daxiao= %d", neicun[i].daxiao);
			printf(" zhuangtai= %d", neicun[i].zhuangtai);
			printf(" info= %s", neicun[i].info);
			flag = 1;
		}
	}
	if (!flag) printf("\n ��ǰû�����н���\n");
}
void huanchu() {
	if (!shumu) {
		printf("��ǰû�����н���\n");
		return;
	}
	printf("\n ���뻻�����̵� ID ֵ");
	scanf("%d", &pid);
	for (int i = 0; i < 20; i++) {
		//��λ���ҵ���Ҫ�����Ľ��̣�������״̬����Ӧ����
		if (pid == neicun[i].pid) {
			if (neicun[i].zhuangtai == 1) {
				neicun[i].zhuangtai = 2;
				guaqi++;
				printf("\n �Ѿ��ɹ���������\n");
			}
			else if (neicun[i].zhuangtai == 0) printf("\n Ҫ�����Ľ��̲�����\n");
			else printf("\n Ҫ�����Ľ����ѱ�����\n");
			flag = 1;
			break;
		}
	}
	//�Ҳ�������˵�����̲�����
	if (flag == 0) printf("\n Ҫ�����Ľ��̲�����\n");
}
void kill() {
	if (!shumu) {
		printf("��ǰû�����н���\n");
		return;
	}
	printf("\n ����ɱ�����̵� ID ֵ");
	scanf("%d", &pid);
	for (int i = 0; i < 20; i++) {
		//��λ���ҵ���Ҫɱ���Ľ��̣�������״̬����Ӧ����
		if (pid == neicun[i].pid) {
			if (neicun[i].zhuangtai == 1) {
				neicun[i].zhuangtai = 0;
				shumu--;
				printf("\n �ѳɹ�ɱ������\n");
			}
			else if (neicun[i].zhuangtai == 0) printf("\n Ҫɱ���Ľ��̲�����\n");
			else printf("\n Ҫɱ���Ľ����ѱ�����\n");
			flag = 1;
			break;
		}
	}
	//�Ҳ�������˵�����̲�����
	if (!flag) printf("\n Ҫɱ���Ľ��̲�����\n");
}
void huanxing() {
	if (!shumu) {
		printf("��ǰû�����н���\n");
		return;
	}
	if (!guaqi) {
		printf("\n ��ǰû�й������\n");
		return;
	}
	printf("\n ���� pid:\n");
	scanf("%d", &pid);
	for (int i = 0; i < 20; i++) {
		//��λ���ҵ���Ҫɱ���Ľ��̣�������״̬����Ӧ����
		if (pid == neicun[i].pid) {
			flag = false;
			if (neicun[i].zhuangtai == 2) {
				neicun[i].zhuangtai = 1;
				guaqi--;
				printf("\n �Ѿ��ɹ����ѽ���\n");
			}
			else if (neicun[i].zhuangtai == 0) printf("\n Ҫ���ѵĽ��̲�����\n");
			else printf("\n Ҫ���ѵĽ����ѱ�����\n");
			break;
		}
	}
	//�Ҳ�������˵�����̲�����
	if (flag) printf("\n Ҫ���ѵĽ��̲�����\n");
}
void main() {
	int n = 1;
	int num;
	//һ��ʼ���н��̶������ڴ���
	for (int i = 0; i < 20; i++)
		neicun[i].zhuangtai = 0;
	while (n) {
		printf("\n********************************************");
		printf("\n* ������ʾϵͳ *");
		printf("\n********************************************");
		printf("\n 1.�����µĽ��� 2.�鿴���н��� ");
		printf("\n 3.����ĳ������ 4.ɱ�����н��� ");
		printf("\n 5.����ĳ������ 6.�˳�ϵͳ ");
		printf("\n********************************************");
		printf("\n ��ѡ��(1��6)\n");
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
		flag = 0;//�ָ����
	}
}