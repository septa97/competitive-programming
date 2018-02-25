#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int main() {
	int n, k, temp, ans = 0;
	vector<int> a;
	cin >> n >> k;;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}

	sort(a.begin(), a.end());

	int i = 0, j = 0;
	while (i != n-1 || j != n-1) {
		if (a[j]-a[i] < k) {
			if (j < n-1) j++;
			else i++;
		}
		else {
			ans += (n-j);
			i++;
		}
	}

	cout << ans << endl;

	return 0;
}