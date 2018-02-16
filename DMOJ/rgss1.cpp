#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[1005];

int max(int x, int y) {
	return (x > y ? x : y);
}

int solve(int a, int b, int c) {
	int mx, mn;
	if (a < b) {
		mx = b;
		mn = a;
	}
	else {
		mx = a; mn = b;
	}

	dp[mn] = mn;
	for (int i = mn; i <= c; i++) {
		if (i >= mx) dp[i] = max(dp[i-mn]+mn, dp[i-mx]+mx);
		else dp[i] = dp[i-mn] + mn;
	}

	return dp[c];
}

int main() {
	memset(dp, 0, sizeof(dp));
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	printf("%d\n", solve(a, b, c));

	return 0;
}