#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int st, en, mid, ans;
int snacks[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n;
	for (int i{}; i < n; i++) {
		cin >> snacks[i];
	}
	sort(snacks, snacks + n);
	st = 1;
	en = snacks[n - 1];
	while (st <= en) {
		int cnt{};
		mid = (st + en) / 2;
		for (int i{ n - 1 }; i >= 0; i--) {
			cnt += snacks[i] / mid;
		}
		if (cnt >= m) {
			st = mid + 1;
			ans = mid;
		}
		else en = mid - 1;
	}
	cout << ans;

	return 0;
}