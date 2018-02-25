#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cmath>

#define MOD 1000000009
#define debug(x) cout << x << " ";
#define debug_newline(x) cout << x << endl;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> p_ii;

int s[505];
int k[505];
int r[505];
int c[505];

bool sort_func(p_ii A, p_ii B) {
	return A.first <  B.first;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<p_ii> packages;
	vector<p_ii> containers;

	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) cin >> k[i];

	for (int i = 0; i < n; i++) packages.push_back(p_ii(s[i], k[i]));
	sort(packages.begin(), packages.end(), sort_func);

	for (int i = 0; i < m; i++) cin >> r[i];
	for (int i = 0; i < m; i++) cin >> c[i];

	for (int i = 0; i < m; i++) containers.push_back(p_ii(r[i], c[i]));
	sort(containers.begin(), containers.end(), sort_func);

	int ans = 0;
	for (int i = 0, j = 0; i < n && j < m; packages[i].second == 0 ? i++ : i) {
		if (sqrt(2 * (packages[i].first * packages[i].first))/2 <= containers[j].first) {
			if (packages[i].second >= containers[j].second) {
				ans += containers[j].second;
				packages[i].second -= containers[j].second;
				containers[j].second = 0;
				j++;
			}
			else {
				ans += packages[i].second;
				containers[j].second -= packages[i].second;
				packages[i].second = 0;
			}
		}
		else {
			j++;
		}
	}

	cout << ans << endl;

	return 0;
}