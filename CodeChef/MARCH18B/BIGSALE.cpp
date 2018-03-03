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

int price[100005], quantity[100005], discount[100005];

int main() {
    int t, n, p, q, d;
    cin >> t;

    while (t--) {
        double before = 0, after = 0;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> p >> q >> d;
            price[i] = p;
            quantity[i] = q;
            discount[i] = d;
             
            before += price[i] * quantity[i];
        }

        for (int i = 0; i < n; i++) {
            double new_price = (price[i] * (1 + (double)discount[i]/100)) * (1-(double)discount[i]/100);
            after += new_price * quantity[i];
        }

        printf("%f\n", before-after);
    }

    return 0;
}
