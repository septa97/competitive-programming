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
    int x, n, ans = 0;
    scanf("%d", &n);
    x = n;

    while (x % 2 == 0) {
        ans++;
        x /= 2;
    }

    for (int i = 3; i <= n/2; i += 2) {
        while (x % i == 0) {
            ans++;
            x /= i;
        }
    }

    if (ans > 0) printf("%d", ans);
    else printf("1");
    return 0;
}
