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
    int n, temp;
    ll total = 0;
    vector<int> a;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.rbegin(), a.rend());

    int take = (n/3) * 2;
    take += n%3;

    for (int i = 0; take != 0; i++) {
        if ((i+1) % 3 != 0) {
            total += a[i];
            take--;
        }
    }

    cout << total << endl;
    
    return 0;
}
