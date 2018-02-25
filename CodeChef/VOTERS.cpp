#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map<int, int> voters;

int main() {
	int n1, n2, n3, temp, m = 0;
	cin >> n1 >> n2 >> n3;

	while (n1--) {
		cin >> temp;
		if (voters[temp] == 1) m++;
		voters[temp]++;
	}

	while (n2--) {
		cin >> temp;
		if (voters[temp] == 1) m++;
		voters[temp]++;
	}

	while (n3--) {
		cin >> temp;
		if (voters[temp] == 1) m++;
		voters[temp]++;
	}

	cout << m << endl;
	for (map<int, int>::iterator it = voters.begin(); it != voters.end(); ++it) {
		if (it->second > 1) cout << it->first << endl;
	}

	return 0;
}