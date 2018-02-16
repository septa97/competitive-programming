#include <cstdio>
#include <cstring>

typedef long long ll;

ll dp[255][255];

ll solve(int n, int k) {
	if (n == 0 && k == 0) {
		return 1;
	}
	else if (n < 0 || k == 0) {
		return 0;
	}
	else if (dp[n][k] != -1) {
		return dp[n][k];
	}

	return dp[n][k] = solve(n-1, k-1) + solve(n-k, k);
}

int main() {
	memset(dp, -1, sizeof dp);
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);

	printf("%lld\n", solve(n, k));

	return 0;
}