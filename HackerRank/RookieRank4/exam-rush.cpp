#include <bits/stdc++.h>

using namespace std;

int examRush(vector <int> tm, int t) {
    // Complete this function
    sort(tm.begin(), tm.end());
    
    int ans = 0;
    for (vector<int>::iterator it = tm.begin(); it != tm.end(); ++it) {
        if (t-*it >= 0) {
            ans++;
            t -= *it;
        }
    }
    
    return ans;
}

int main() {
    int n;
    int t;
    cin >> n >> t;
    vector<int> tm(n);
    for(int tm_i = 0; tm_i < n; tm_i++){
       cin >> tm[tm_i];
    }
    int result = examRush(tm, t);
    cout << result << endl;
    return 0;
}
