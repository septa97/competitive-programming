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

#define MOD 1000000009
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

ll DP[45][40005];
int A[45];

ll solve(int i, int total) {
    if (i < 0) {
        if (total >= 200) return total;
        else return 0;
    }
    else if (DP[i][total] != -1) {
        return DP[i][total];
    }

    return DP[i][total] = solve(i-1, total+A[i]) + solve(i-1, total);
}

int main() {
    memset(DP, -1, sizeof DP);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];

    cout << solve(n-1, 0);

    return 0;
}
