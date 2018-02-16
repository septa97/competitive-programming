#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
    vector<int> v;
    int n, temp;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        printf("%d\n", *it);
    }

    return 0;
}
