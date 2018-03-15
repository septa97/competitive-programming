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

double average;

bool above_average(int num) {
    return num > average;
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> V(n);

        for (int i = 0; i < n; i++) cin >> V[i];

        average = accumulate(V.begin(), V.end(), 0.0)/n;

        printf("%.3f%%\n", (double)count_if(V.begin(), V.end(), above_average)/n*100);
    }

    return 0;
}
