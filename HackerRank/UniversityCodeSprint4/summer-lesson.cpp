#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <cstring>

#define MOD 1000000009
#define debug(x) cout << x << " ";
#define debug_newline(x) cout << x << endl;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> p_ii;

int s[1005];

int main() {
	memset(s, 0, sizeof s);
	int n, m, temp;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		s[temp]++;
	}

	for (int i = 0; i < m; i++) {
		cout << s[i] << " ";
	}

	return 0;
}