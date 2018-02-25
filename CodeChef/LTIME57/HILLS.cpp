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

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int H[105];

int main() {
	int t, n, u, d;
	cin >> t;

	while (t--) {
		cin >> n >> u >> d;
		bool used = false;
		bool stopped = false;

		for (int i = 0; i < n; i++) {
			cin >> H[i];
		}

		for (int i = 0; i < n-1; i++) {
			if (H[i+1] > H[i]) {
				if (H[i+1]-H[i] > u) {
					cout << i+1 << endl;
					stopped = true;
					break;
				}
			}
			else if (H[i+1] < H[i]) {
				if (H[i]-H[i+1] > d) {
					if (!used) {
						used = true;
					}
					else {
						cout << i+1 << endl;
						stopped = true;
						break;
					}
				}
			}
		}

		if (!stopped) cout << n << endl;
	}

	return 0;
}