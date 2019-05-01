#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
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
    int m;
    char p;
    string result;
    map<char, int> mp;
    int solved = 0, time_measure = 0;

    while ((cin >> m) && m != -1) {
        cin >> p >> result;

        if (result == "right") {
            map<char, int>::iterator mp_it = mp.find(p);

            time_measure += m;
            solved++;
            if (mp_it != mp.end()) {
                time_measure += 20 * mp_it->second;
            }
        } else {
            mp[p] += 1;
        }
    }

    cout << solved << " " << time_measure << endl;

    return 0;
}
