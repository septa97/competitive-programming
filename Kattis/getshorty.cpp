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

double dist[10005];

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

struct Comp {
    bool operator()(pair<int, double> a, pair<int, double> b) {
        return a.second < b.second;
    }
};

int main() {
    int n, m;

    while ((cin >> n >> m) && (n && m)) {
        map<int, vector<pair<int, double>>> adj_list;
        priority_queue<pair<int, double>, vector<pair<int, double>>, Comp> Q;

        for (int i = 1; i < n; i++) {
            dist[i] = 0.0;
            Q.push(make_pair(i, 0.0));
        }
        dist[0] = 1.0;
        Q.push(make_pair(0, 1.0));

        for (int i= 0; i < m; i++) {
            int a, b;
            double d;
            cin >> a >> b >> d;

            if (adj_list.find(a) == adj_list.end()) {
                vector<pair<int, double>> v;
                v.push_back(make_pair(b, d));
                adj_list[a] = v;
            }
            else {
                adj_list[a].push_back(make_pair(b, d));
            }

            if (adj_list.find(b) == adj_list.end()) {
                vector<pair<int, double>> v;
                v.push_back(make_pair(a, d));
                adj_list[b] = v;
            }
            else {
                adj_list[b].push_back(make_pair(a, d));
            }
        }

        while (!Q.empty()) {
            pair<int, double> u = Q.top();
            Q.pop();
        
            // You don't have to wait for the queue to be empty if you already reached the last node
            if (u.first == n-1) {
                printf("%.4f\n", dist[n-1]);
                break;
            }

            for (int i = 0; i < adj_list[u.first].size(); i++) {
                double curr_dist = dist[u.first] * adj_list[u.first][i].second;
                if (curr_dist > dist[adj_list[u.first][i].first]) {
                    dist[adj_list[u.first][i].first] = curr_dist;
                    Q.push(make_pair(adj_list[u.first][i].first, curr_dist));
                }
            }
        }
    }

    return 0;
}
