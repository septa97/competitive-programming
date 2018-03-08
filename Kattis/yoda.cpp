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

int main() {
    int a, b;
    string a_str, b_str;
    a_str = "";
    b_str = "";
    cin >> a;
    cin >> b;

    while (a > 0 || b > 0) {
        int a_rem = a % 10;
        int b_rem = b % 10;

        if (a_rem > b_rem) {
            a_str = to_string(a_rem) + a_str;
        }
        else if (a_rem < b_rem) {
            b_str = to_string(b_rem) + b_str;
        }
        else {
            a_str = to_string(a_rem) + a_str;
            b_str = to_string(b_rem) + b_str;
        }

        a /= 10; b /= 10;
    }

    if (a_str == "") cout << "YODA" << "\n";
    else cout << (stoi(a_str)) << "\n";

    if (b_str == "") cout << "YODA" << "\n";
    else cout << (stoi(b_str)) << "\n";

    return 0;
}
