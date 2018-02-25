#include <iostream>

using namespace std;

int main() {
	int n, a, b, a_total, b_total;
	a_total = b_total = 0;
	cin >> n;

	int ans;
	int lead = -1;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		a_total += a;
		b_total += b;

		int temp = abs(a_total-b_total);
		if (temp > lead) {
			lead = temp;

			if (a_total > b_total) {
				ans = 1;
			}
			else {
				ans = 2;
			}
		}
	}

	cout << ans << " " << lead << endl;

	return 0;
}