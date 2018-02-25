#include <iostream>

using namespace std;

int stack[100005];

int main() {
	int n, h, command, crane = 0;
	bool has_box = false;
	cin >> n >> h;

	for (int i = 0; i < n; i++) cin >> stack[i];

	cin >> command;
	while (command != 0) { 
		if (command == 1) {
			if (crane > 0) crane--;
		}
		else if (command == 2) {
			if (crane < n-1) crane++;
		}
		else if (command == 3) {
			if (!has_box && stack[crane] > 0) {
				has_box = true;
				stack[crane]--;
			}
		}
		else if (command == 4) {
			if (has_box && stack[crane] < h) {
				has_box = false;
				stack[crane]++;
			}
		}

		cin >> command;
	}

	for (int i = 0; i < n; i++) cout << stack[i] << " ";

	return 0;
}