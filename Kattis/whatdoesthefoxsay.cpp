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

vector<string> delete_existing(vector<string> recording, string curr) {
    vector<string>::iterator it = recording.begin();

    while (it != recording.end()) {
        if (*it == curr) it = recording.erase(it);
        else ++it;
    }

    return recording;
}

int main() {
    string s, temp;
    int t;
    cin >> t;
    getchar();

    while (t--) {
        getline(cin, s);
        vector<string> recording = split(s, " ");

        getline(cin, temp);
        while (temp != "what does the fox say?") {
            vector<string> a = split(temp, " ");
            recording = delete_existing(recording, a[a.size()-1]);
            getline(cin, temp);
        }

        for (int i = 0; i < recording.size(); i++) {
            cout << recording[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
