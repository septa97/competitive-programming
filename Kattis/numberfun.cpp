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

int main() {
    int n, a, b, c;
    cin >> n;

    while (n--) {
        cin >> a >> b >> c;

        if (a+b == c) {
            cout << "Possible" << "\n";
        }
        else if (abs(a-b) == c) {
            cout << "Possible" << "\n";
        }
        else if (a*b == c) {
            cout << "Possible" << "\n";
        }
        else if (a/b == c && a%b == 0 || b/a == c && b%a == 0) {
            cout << "Possible" << "\n";
        }
        else {
            cout << "Impossible" << "\n";
        }
    }

    return 0;
}
