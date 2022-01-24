/*钻石奖励
海盗们决定用“投环套物”的方式来奖励最近一次行动中贡献最大的人。
他们将1克拉钻石排列成矩阵，通过投掷圆环决定奖励的钻石的数量。假
设每个钻不的x和y坐标都是1到99的整数，输入矩阵及圆形，请你帮他们
判断一下这个人能获得多省克拉的钻石。
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
	for (i = 1; i <= n; i++) {//遍历每一个坐标点，一旦左边点比r小或者等于，那么一定是这个圆圈内的坐标点
		for (j = 1; j <= m; j++) {
			l = sqrt((i - x) * (i - x) + (j - y) * (j - y));//俩点之间距离公式
			if (l <= r)
				count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
#endif