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

int A[1000005];
int B[1000005];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];

    int j = 1;
    int curr = A[0];
    B[0] = A[0];

    for (int i = 1; i < n; i++) {
        if (A[i] > curr) {
            curr = A[i];
            B[j] = curr;
            j++;
        }
    }

    cout << j << "\n";
    for (int i = 0; i < j; i++) {
        cout << B[i] << " ";
    }

    return 0;
}
