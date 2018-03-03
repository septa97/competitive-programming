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

int L[100005];
int G[100005];

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        bool a, b;
        a = b = true;

        for (int i = 0; i < n; i++) cin >> L[i];
        for (int i = 0; i < n; i++) cin >> G[i];

        // front
        for (int i = 0; i < n; i++) {
            if (L[i] > G[i]) {
                a = false;
                break;
            }
        }

        // back
        for (int i = n-1, j = 0; i >= 0; i--, j++) {
            if (L[j] > G[i]) {
                b = false;
                break;
            }
        }

        if (a && b) cout << "both" << "\n";
        else if (a) cout << "front" << "\n";
        else if (b) cout << "back" << "\n";
        else cout << "none" << "\n";
    }

    return 0;
}
