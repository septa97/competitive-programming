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
    int n;
    cin >> n;
    getchar();

    while (n) {
        vector<pair<string, int>> files;

        for (int i = 0; i < n; i++) {
            string s;
            getline(cin, s);

            int hash = s[0];
            for (int j = 1; j < s.size(); j++) {
                hash ^= s[j];
            }

            files.push_back(make_pair(s, hash));
        }

        int unique = 0, collisions = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i+1; j < n; j++) {
                if (files[i].first != files[j].first && files[i].second == files[j].second) collisions++;
                if (files[i].first != files[j].first) count++;
            }

            if (count == n-i-1) unique++;
        }

        cout << unique << " " << collisions << "\n";
        cin >> n;
        getchar();
    }

    return 0;
}
