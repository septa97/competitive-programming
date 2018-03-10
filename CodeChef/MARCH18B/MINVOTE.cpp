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

ll A[100005];
int B[100005];

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
    int t, n, temp;
    cin >> t;

    while (t--) {
        cin >> n;

        cin >> A[0];
        B[0] = n > 1 ? 1 : 0;
        for (int i = 1; i < n; i++) {
            cin >> temp;
            A[i] = A[i-1] + temp;
            if (i < n-1) B[i] = 2;
            else B[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+2; j < n; j++) {
                if ((i > 0 ? A[i]-A[i-1] : A[i]) >= A[j-1]-A[i]) {
                    B[j]++;
                }
                else break;
            }
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = i-2; j >= 0; j--) {
                if ((i > 0 ? A[i]-A[i-1] : A[i]) >= A[i-1]-A[j]) {
                    B[j]++;
                }
                else break;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << B[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
