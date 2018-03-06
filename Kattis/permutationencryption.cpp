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
#define debug(x) cout << x << " ";
#define debug_newline(x) cout << x << endl;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0) // for unsigned integral data types

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> p_ii;

int main() {
    int n, temp;
    string s, ans;
    
    cin >> n;
    while (n > 0) {
        vector<int> a;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            a.push_back(temp);
        }

        getchar();
        getline(cin, s);

        int pad = s.length() % n;
        pad = n - pad;

        if (pad != n) {
            while (pad--) {
                s += ' ';
            }
        }

        ans = "'";
        for (int i = 0, j = 0; j+i < s.length(); i++) {
            if (i == n) {
                i = 0;
                j += n;
            }

            ans += s[j+a[i]-1];
        }

        ans += '\'';

        cout << ans << "\n";
        cin >> n;
    }


    return 0;
}
