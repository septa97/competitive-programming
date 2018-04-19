#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
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

int C[1005];
int T[1005];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> C[i];
    for (int i = 0; i < n; i++) cin >> T[i];

    int t, a, at;
    t = a = at = INF;

    for (int i = 0; i < n; i++) {
        if (T[i] == 1) t = min(t, C[i]);
        else if (T[i] == 2) a = min(a, C[i]);
        else at = min(at, C[i]);
    }

    cout << min(a+t, at);

    return 0;
}
