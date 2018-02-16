#include <iostream>
#include <cstdlib>

#define max(x, y) (x > y ? x : y)

using namespace std;

int b[100005];
int dp[100005][2];

int solve(int n) {
	dp[0][0] = abs(b[1]-1);
	dp[0][1] = abs(1-b[0]);

	for (int i = 1; i < n-1; i++) {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]+abs(b[i+1]-1));
		dp[i][1] = max(dp[i-1][0]+abs(1-b[i]), dp[i-1][1]);
	}

	return max(dp[n-2][0], dp[n-2][1]);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		cout << solve(n) << endl;
	}
	
	return 0;
}