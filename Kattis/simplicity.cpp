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

int cnt[26];

int main() {
	memset(cnt, 0, sizeof cnt);
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		cnt[s[i]-'a']++;
	}

	sort(cnt, cnt+26);

	int simplicity = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 0) simplicity++;
	}

	if (simplicity <= 2) cout << "0" << endl;
	else {
		int ans = 0;
		for (int i = 0; (simplicity-2) > 0; i++) {
			if (cnt[i] > 0) {
				ans += cnt[i];
				simplicity--;
			}
		}

		cout << ans << endl;
	}

	return 0;
}