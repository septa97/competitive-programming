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

char A[25][25];

int main() {
    int t, r, c;
    cin >> t;

    for (int x = 1; x <= t; x++) {
        cin >> r >> c;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> A[i][j];

        cout << "Test " << x << "\n";

        for (int i = r-1; i >= 0; i--) {
            for (int j = c-1; j >= 0; j--) {
                cout << A[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
