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
#define min(x, y) x < y ? x : y
#define max(x, y) x > y ? x : y
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
    int t, n;
    string s;
    cin >> t;

    while (t--) {
        cin >> s >> n;
        int s_len = s.size();
        int curr = 0, pos = 0;

        for (int i = 0; i < s_len; i++) {
            curr += s[i] == 'a' ? 1 : -1;
            if (curr > 0) pos++;
        }

        if (curr == 0) {
            cout << ((ll)pos*n) << "\n";
        }
        else if (curr > 0) {
            ll ans = 0;
            int c = 0;

            while (pos < s_len && c < n) {
                ans += pos;
                pos = 0;
                for (int i = 0; i < s_len; i++) {
                    curr += s[i] == 'a' ? 1 : -1;
                    if (curr > 0) pos++;
                }
                
                c++;
            }

            cout << (ans + (ll)s_len*(n-c)) << "\n";
        }
        else if (curr < 0) {
            ll ans = 0;
            int c = 0;

            while (pos > 0 && c < n) {
                ans += pos;
                pos = 0;
                for (int i = 0; i < s_len; i++) {
                    curr += s[i] == 'a' ? 1 : -1;
                    if (curr > 0) pos++;
                }

                c++;
            }

            cout << ans << "\n";
        }
    }

    return 0;
}
