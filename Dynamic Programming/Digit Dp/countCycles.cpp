#include <bits/stdc++.h>
 
using namespace std;
 
char g[19][19];
long long a[1 << 19][19];
 
int main ()
{
	int N, M;
	scanf("%d %d",&N,&M);
	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d",&x,&y);
		g[y][x] = g[--x][--y] = 1;
	}
	long long res = 0LL;
	for (int x = 0; x < N; x++) a[1 << x][x] = 1;
	for (int i = 0; i < 1 << N; i++)
		for (int j = 0; j < N; j++)
			if (a[i][j]) {
				if (g[j][__builtin_ffs(i) - 1] && __builtin_popcount(i) > 2) res += a[i][j];
				for (int k = __builtin_ffs(i); k < N; k++)
					if (!(i & 1 << k) && g[j][k]) a[i | 1 << k][k] += a[i][j];
			}
	printf("%lli\n",res / 2LL);
	return 0;
}