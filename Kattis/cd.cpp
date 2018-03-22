#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
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
    int n, m, temp;
    cin >> n >> m;

    while (n != 0 && m != 0) {
        int ans = 0;
        unordered_set<int> A;

        for (int i = 0; i < n; i++) {
            cin >> temp;
            A.insert(temp);
        }

        for (int i = 0; i < m; i++) {
            cin >> temp;
            if (A.find(temp) != A.end()) {
                A.erase(temp);
                ans++;
            }
        }

        cout << ans << "\n";
        cin >> n >> m;
    }

    return 0;
}
