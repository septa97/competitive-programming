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

bool is_vowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') return true;
    else return false;
}

int main() {
    string s;

    while (getline(cin, s)) {
        vector<string> A;

        int pos = s.find(' ');
        int curr = 0;

        while (pos != -1) {
            A.push_back(s.substr(curr, curr+pos));
            s = s.substr(curr+pos+1);
            pos = s.find(' ');
        }

        A.push_back(s);

        string ans = "";
        for (int i = 0; i < A.size(); i++) {
            if (!is_vowel(A[i][0])) {
                string curr = "";
                int j = 0;
                while (j < A[i].length() && !is_vowel(A[i][j])) {
                    curr += A[i][j];
                    j++;
                }

                if (j < A[i].length()) ans += A[i].substr(j) + curr + "ay ";
                else ans += A[i] + curr + "ay ";
            }
            else {
                ans += A[i] + "yay ";
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
