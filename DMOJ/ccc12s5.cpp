#include <cstdio>
#include <cstring>

#define max(x, y) (x > y ? x : y)

int dp[30][30];
int r, c;

int solve() {
	for (int i = 2; i <= r; i++) {
		for (int j = 2; j <= c; j++) {
			if (dp[i][j] != -1) dp[i][j] = max(dp[i-1][j], 0) + max(dp[i][j-1], 0);
		}
	}

	return dp[r][c];
}

void init() {
	for (int i = 2; i <= r; i++) dp[i][1] = (dp[i-1][1] == -1 || dp[i][1] == -1 ? -1 : 1);
	for (int i = 2; i <= c; i++) dp[1][i] = (dp[1][i-1] == -1 || dp[1][i] == -1 ? -1 : 1);
}

int main() {
	memset(dp, 0, sizeof dp);
	dp[1][1] = 1;
	int k, a, b;
	scanf("%d %d", &r, &c);
	scanf("%d", &k);

	while (k--) {
		scanf("%d %d", &a, &b);
		dp[a][b] = -1;
	}
	init();

	printf("%d\n", solve());

	return 0;
}