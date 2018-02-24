#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main() {
	map<char, int> count;
	int n;
	string s;
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		count[s[i]]++;
	}

	if (n % 2 != 0) {
		cout << "No";
		return 0;
	}

	for (map<char, int>::iterator it = count.begin(); it != count.end(); ++it) {
		if (it->second > n/2) {
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";

	return 0;
}