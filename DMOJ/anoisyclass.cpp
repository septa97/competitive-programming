#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

bool visited[10005];
map<int, vector<int> > adj_list;

bool dfs(int v) {
    if (!visited[v]) {
        visited[v] = true;

        for (vector<int>::iterator it = adj_list[v].begin(); it != adj_list[v].end(); ++it) {
            if (!visited[*it] && dfs(*it)) {
                return true;
            }
            else if (visited[*it]) {
                return true;
            }
        }

        visited[v] = false;
    }

    return false;
}

bool hasCycle(int n) {
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(bool));

        if (dfs(i)) return true;
    }

    return false;
}

int main() {
    int n, m, noisy, distracted;
    
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &noisy, &distracted);

        if (adj_list.find(noisy) == adj_list.end()) {
            vector<int> v;
            v.push_back(distracted);
            adj_list[noisy] = v;
        }
        else {
            adj_list[noisy].push_back(distracted);
        }
    }

    if (hasCycle(n)) {
        printf("N\n");
    }
    else {
        printf("Y\n");
    }

    return 0;
}
