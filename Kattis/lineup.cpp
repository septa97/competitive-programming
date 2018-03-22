#include <iostream>
#include <vector>
#include <map>
#include <set>
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
    bool inc;
    int n;
    cin >> n;
    vector<string> A(n);

    for (int i = 0; i < n; i++) cin >> A[i];

    if (A[0].compare(A[1]) < 0) inc = true;
    else if (A[0].compare(A[1]) > 0) inc = false;
    else {
        cout << "NEITHER";
        return 0;
    }

    for (int i = 2; i < n; i++) {
        if (A[i-1].compare(A[i]) < 0) {
            if (!inc) {
                cout << "NEITHER";
                return 0;
            }
        }
        else if (A[i-1].compare(A[i]) > 0) {
            if (inc) {
                cout << "NEITHER";
                return 0;
            }
        }
        else {
            cout << "NEITHER";
            return 0;
        }
    }

    if (inc) cout << "INCREASING";
    else cout << "DECREASING";

    return 0;
}
