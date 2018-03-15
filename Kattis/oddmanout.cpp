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

int main() {
    int n, g, c;
    cin >> n;

    for (int t = 1; t <= n; t++) {
        map<int, int> M;
        cin >> g;

        for (int i = 0; i < g; i++) {
            cin >> c;
            if (M[c] == 1) {
                M[c] = 0;
            }
            else {
                M[c]++;
            }
        }

        for (map<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
            if (it->second == 1) {
                printf("Case #%d: %d\n", t, it->first);
                break;
            }
        }
    }

    return 0;
}
