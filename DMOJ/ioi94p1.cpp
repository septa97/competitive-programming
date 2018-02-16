#include <cstdio>
#include <cstring>

int dp[105][105];

int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	memset(dp, 0, sizeof(dp));
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			scanf("%d", &dp[i][j]);
		}
	}

	int ans = dp[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			if (j > 0) dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
			else dp[i][j] += dp[i-1][j];

			if (dp[i][j] > ans) ans = dp[i][j];
		}
	}

	printf("%d\n", ans);

	return 0;
}