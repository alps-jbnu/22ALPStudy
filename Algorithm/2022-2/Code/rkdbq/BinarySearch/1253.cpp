#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
pair<int, int> a[2001];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);

	for (int i{ n - 1 }; i >= 0; i--) {
		bool chk{};
		auto isGood = a[i];
		for (int j{ n - 1 }; j >= 0; j--) {
			if (j == i) continue;
			if (chk) break;
			pair<int, int> toFind = { isGood.first - a[j].first, 0 };
			auto lb = lower_bound(a, a + n, toFind);
			while (true) {
				if ((*lb).first != toFind.first) break;
				if ((*lb).first == toFind.first && (*lb).second != a[j].second && (*lb).second != isGood.second) {
					//cout << isGood.first << "\n";
					ans++;
					chk = true;
					break;
				}
				lb++;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}