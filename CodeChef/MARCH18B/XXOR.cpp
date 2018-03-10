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
#define max(x, y) (x > y ? x : y)
#define debug(x) cout << (x) << " ";
#define debug_newline(x) cout << (x) << endl;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0) // for unsigned integral data types

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> p_ii;

int A[100005][32][2];

int count_bits(int type, int num, int bit) {
    return (((num >> bit)&1) == type);
}

int main() {
    memset(A, 0, sizeof A);
    int n, q, l, r, temp;
    int ans = pow(2, 31)-1;
    cin >> n >> q;

    cin >> temp;
    for (int i = 0; i < 32; i++) {
        A[0][i][0] = count_bits(0, temp, i);
        A[0][i][1] = count_bits(1, temp, i);
    }

    for (int i = 1; i < n; i++) {
        cin >> temp;

        for (int j = 0; j < 32; j++) {
            A[i][j][0] = A[i-1][j][0] + count_bits(0, temp, j);
            A[i][j][1] = A[i-1][j][1] + count_bits(1, temp, j);
        }
    }

    while (q--) {
        cin >> l >> r;
        l--; r--;
        int num = 0;

        if (l == 0) {
            for (int i = 0; i < 32; i++) {
                if (A[r][i][0] > A[r][i][1]) num |= 0 << i;
                else num |= 1 << i;
            }
        }
        else {
            for (int i = 0; i < 32; i++) {
                if (A[r][i][0]-A[l-1][i][0] > A[r][i][1]-A[l-1][i][1]) num |= 0 << i;
                else num |= 1 << i;
            }
        }

        cout << (ans-num) << "\n";
    }

    return 0;
}
