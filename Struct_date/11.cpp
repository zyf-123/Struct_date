/*��ʯ����
�����Ǿ����á�Ͷ������ķ�ʽ���������һ���ж��й��������ˡ�
���ǽ�1������ʯ���гɾ���ͨ��Ͷ��Բ��������������ʯ����������
��ÿ���겻��x��y���궼��1��99���������������Բ�Σ����������
�ж�һ��������ܻ�ö�ʡ��������ʯ��
*/
#if 0;
#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
int main() {
	int n, m;
	int i, j, count;
	float x, y, r, l;
	scanf("%d %d", &n, &m);
	scanf("%f %f %f", &x, &y, &r);
	count = 0;
	for (i = 1; i <= n; i++) {//����ÿһ������㣬һ����ߵ��rС���ߵ��ڣ���ôһ�������ԲȦ�ڵ������
		for (j = 1; j <= m; j++) {
			l = sqrt((i - x) * (i - x) + (j - y) * (j - y));//����֮����빫ʽ
			if (l <= r)
				count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
#endif