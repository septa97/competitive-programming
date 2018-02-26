#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <cstring>

#define MOD 1000000009
#define debug(x) cout << x << " ";
#define debug_newline(x) cout << x << endl;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0) // for unsigned integral data types

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> p_ii;

int main() {
	vector<int> a;
	a.push_back(0);
	set<int> ans;
	int w, p, temp;
	cin >> w >> p;

	for (int i = 0; i < p; i++) {
		cin >> temp;
		a.push_back(temp);
	}

	a.push_back(w);

	for (int i = 0; i < a.size(); i++) {
		for (int j = i+1; j < a.size(); j++) {
			ans.insert(a[j]-a[i]);
		}
	}

	for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}