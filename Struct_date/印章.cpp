#if 0;
#include <iostream>
#include<cmath>
using namespace std;
double dp[21][21] = { 0.0000 };
int main()
{
	int n, m, i, j;
	cin >> n >> m;
	double p = 1.0 / n;
	for (i = 1; i <= m; i++) {
		dp[i][1] = pow(p, i - 1);
	}
	for (j = 2; j <= n; j++) {
		for (i = 2; i <= m; i++) {
			dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) * 1.0 / n + dp[i - 1][j] * (j * 1.0) / n;
		}
	}
	//cout.precision(6);
	//cout<< dp[m][n];
	printf("%.4lf", dp[m][n]);
	return 0;
}
#endif