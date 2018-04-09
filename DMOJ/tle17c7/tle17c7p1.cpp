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

int main() {
    int n, p, x, y;
    int ans = 1;
    cin >> n;
    vector<p_ii> A(n+2);
    A[1] = make_pair(0, 0);

    for (int i = 2; i <= n; i++) {
        cin >> p >> x >> y;
        p_ii temp = make_pair(x+A[p].first, y+A[p].second);

        if (find(A.begin(), A.end(), temp) == A.end()) {
            ans++;
        }

        A[i] = temp;
    }

    cout << ans << "\n";

    return 0;
}
