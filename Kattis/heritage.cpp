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
#include <cmath>

#define MOD 1000000007
#define INF 1000000000
#define debug(x) cout << x << " ";
#define debug_newline(x) cout << x << "\n";
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0) // for unsigned integral data types

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> p_ii;

vector<string> split(string s, string delimiter) {
    int pos = s.find(delimiter);
    vector<string> a;

    while (pos != -1) {
        a.push_back(s.substr(0, pos));
        s = s.substr(pos+1);
        pos = s.find(delimiter);
    }

    a.push_back(s);

    return a;
}

map<pair<string, int>, int> DP;
string A_s[1005];
int A_m[1005];

int solve(string s, string name, int total, int n) {
    pair<string, int> p = make_pair(s, total);

    if (s.size() > name.size()) return 0;
    else if (s == name) return total;
    else if (DP.find(p) != DP.end()) return DP[p];

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (name.substr(s.size(), A_s[i].size()) == A_s[i]) {
            ans += solve(s+A_s[i], name, ((ll)total*A_m[i])%MOD, n);
        }
    }

    return DP[p] = ans%MOD;
}

int main() {
    int n;
    string name;
    cin >> n >> name;

    for (int i = 0; i < n; i++) {
        cin >> A_s[i] >> A_m[i];
    }

    cout << solve("", name, 1, n);

    return 0;
}
