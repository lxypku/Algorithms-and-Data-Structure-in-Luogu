#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, a[2001][2001], f[2001][2001];

int main(){
	// 读入
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d",&a[i][j]);
	// 赋动规初值
	for (int i = 0; i < m; i++)
		f[i][1] = a[i][1];
	// 动态规划
	for (int j = 2; j <= n; j++)
		for (int i = 0; i < m; i++)
			f[i][j] = min(f[i][j-1],f[(i+m-1)%m][j-1])+a[i][j];
	// 得到答案
	int ans = f[0][n];
	for (int i = 1; i < m; i++)
		ans = min(ans, f[i][n]);
	printf("%d\n",ans);
	return 0;
}