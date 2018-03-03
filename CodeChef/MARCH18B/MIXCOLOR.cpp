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

int main() {
    int t, n, temp;
    scanf("%d", &t);

    while (t--) {
        int ans = 0;
        map<int, int> count;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            if (count[temp] >= 1) ans++;
            count[temp]++;
        }

        printf("%d\n", ans);
    }
    return 0;
}
