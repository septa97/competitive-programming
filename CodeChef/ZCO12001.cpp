#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int main() {
	int n, temp, curr = 0, depth = 0, first_depth, symbols = 0, first_symbol, temp_symbol;
	cin >> n;

	for (int i = 1, curr_symbols = 0; i <= n; i++) {
		cin >> temp;
		curr_symbols++;

		if (temp == 1) {
			if (curr == 0) {
				temp_symbol = i;
			}
			
			curr++;

			if (curr > depth) first_depth = i;
			depth = max(curr, depth);
		}
		else {
			curr--;

			if (curr == 0) {
				if (curr_symbols > symbols) first_symbol = temp_symbol;
				symbols = max(symbols, curr_symbols);
				curr_symbols = 0;
			}
		}
	}

	cout << depth << " " << first_depth << " " << symbols << " " << first_symbol << endl;

	return 0;
}