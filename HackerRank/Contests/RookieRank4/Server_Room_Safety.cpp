#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int position[105];
int height[105];
bool left_fall[105];
bool right_fall[105];

int main() {
    memset(left_fall, false, sizeof left_fall);
    memset(right_fall, false, sizeof right_fall);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> position[i];
    for (int i = 0; i < n; i++) cin >> height[i];

    // left to right
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (position[i] + height[i] >= position[j]) {
                left_fall[j] = true;
            }
        }
    }

    // right to left
    for (int i = n-1; i > 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            if (position[i] - height[i] <= position[j]) {
                right_fall[j] = true;
            }
        }
    }

    bool left = left_fall[1], right = right_fall[n-2];
    for (int i = 2; i < n; i++) left = left && left_fall[i];
    for (int i = n-3; i >= 0; i--) right = right && right_fall[i];

    if (left && right) cout << "BOTH" << endl;
    else if (left && !right) cout << "LEFT" << endl;
    else if (!left && right) cout << "RIGHT" << endl;
    else cout << "NONE" << endl;

    return 0;
}
