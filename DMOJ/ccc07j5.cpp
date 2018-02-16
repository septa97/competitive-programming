#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> arr;

void init() {
	arr.push_back(0);
	arr.push_back(990);
	arr.push_back(1010);
	arr.push_back(1970);
	arr.push_back(2030);
	arr.push_back(2940);
	arr.push_back(3060);
	arr.push_back(3930);
	arr.push_back(4060);
	arr.push_back(4970);
	arr.push_back(5030);
	arr.push_back(5990);
	arr.push_back(6010);
	arr.push_back(7000);
}

int solve(int a, int b, int curr, int m) {
	if (curr >= 7000) {
		return 1;
	}

	int ans = 0;
	for (int i = m; i < arr.size(); i++) {
		if (curr + a <= arr[i] && curr + b >= arr[i]) {
			ans += solve(a, b, arr[i], i+1);
		}
	}

	return ans;
}

int main() {
	init();

	int a, b, n, m;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &n);

	while (n--) {
		scanf("%d", &m);
		arr.push_back(m);
	}

	sort(arr.begin(), arr.end());

	printf("%d\n", solve(a, b, 0, 1));

	return 0;
}