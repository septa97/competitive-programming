#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main() {
	int n;
	string name, temp;
	cin >> n;
	getchar();
	getline(cin, name);

	while (n--) {
		getline(cin, temp);
		while (temp.size() && isspace(temp.front())) temp.erase(temp.begin());
		while (temp.size() && isspace(temp.back())) temp.pop_back();

		int split = temp.find(" ");
		string left, right;

		if (split != -1) { // if has name
			left = temp.substr(0, split);
			right = temp.substr(split+1, temp.length());

			split = left.find("/");

			int x = stoi(left.substr(0, split));
			int y = stoi(left.substr(split+1, left.length()));

			if (x > y && right == name.substr(0, right.length())) cout << "Y" << endl;
			else cout << "N" << endl;
		}
		else { // if no name found
			left = temp;
			split = left.find("/");

			if (split != -1 && split < left.length()-1) {
				int x = stoi(left.substr(0, split));
				int y = stoi(left.substr(split+1, left.length()));

				if (x > y) cout << "Y" << endl;
				else cout << "N" << endl;
			}
			else {
				cout << "Y" << endl;
			}
		}
	}

	return 0;
}