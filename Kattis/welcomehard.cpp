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
#define debug_newline(x) cout << x << "\n";
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0) // for unsigned integral data types

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> p_ii;

int DP[505][20];

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

int solve(string a, string b, int m, int n) {
    if ((m == 0 && n == 0) || n == 0) return 1;
    if (m == 0) return 0;
    if (DP[m][n] != -1) return DP[m][n];
    if (a[m-1] == b[n-1]) {
        DP[m][n] = solve(a, b, m-1, n-1) + solve(a, b, m-1, n);

        if (DP[m][n] >= 10000) {
            DP[m][n] -= 10000;
        }

        return DP[m][n];
    }
    else {
        DP[m][n] = solve(a, b, m-1, n);
        
        if (DP[m][n] >= 10000) {
            DP[m][n] -= 10000;
        }

        return DP[m][n];
    }
}

int main() {
    string s;
    string a = "welcome to code jam";
    int t;
    cin >> t;
    getchar();

    for (int c = 1; c <= t; c++) {
        memset(DP, -1, sizeof DP);
        getline(cin, s);
        string temp = to_string(solve(s, a, s.size(), a.size()));

        if (temp.size() > 4) temp = temp.substr(temp.size()-4);
        else if (temp.size() < 4) {
            int zeroes = 4-temp.size();

            while (zeroes--) temp = "0" + temp;
        }

        cout << "Case #" << c << ": " << temp << "\n";
    }

    return 0;
}
