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

int exp_by_squaring(ll x, ll n) {
    x %= MOD;
    if (n == 0) return 1;
    else if (n == 1) return x;
    else if (n % 2 == 1) return (x * exp_by_squaring(x * x, (n-1)/2)) % MOD;
    else if (n % 2 == 0) return exp_by_squaring(x * x, n/2);
}

int main() {
    int t, w;
    ll n;
    cin >> t;

    while (t--) {
        cin >> n >> w;

        if (w >= 0 && w <= 8) {
            int ans = 9-w;
            ans = ((ll)ans * exp_by_squaring(10, n-2)) % MOD;
            cout << ans << "\n";
        }
        else if (w < 0 && w >= -8) {
            int ans = 10-abs(w);
            ans = ((ll)ans * exp_by_squaring(10, n-2)) % MOD;
            cout << ans << "\n";
        }
        else if (w == -9) {
            int ans = 1;
            ans = ((ll)ans * exp_by_squaring(10, n-2)) % MOD;
            cout << ans << "\n";
        }
        else {
            cout << "0" << "\n";
        }
    }

    return 0;
}
