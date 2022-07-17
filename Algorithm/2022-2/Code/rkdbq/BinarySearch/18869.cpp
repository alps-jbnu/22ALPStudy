#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
pair<int, int> planet[101][10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i{}; i < n; i++) {
		int eq{};
		for (int j{}; j < m; j++) {
			cin >> planet[i][j].first;
			if (j > 1 && planet[i][j].first == planet[i][j - 1].first) eq--;
			planet[i][j].second = eq++;
		}	
	}
	for (int i{}; i < n; i++) sort(planet[i], planet[i] + m);
	for (int i{}; i < n - 1; i++) {
		for (int j{ i + 1 }; j < n; j++) {
			bool chk{};
			for (int k{}; k < m; k++) {
				if (planet[i][k].second != planet[j][k].second) {
					chk = true;
					break;
				}
			}
			if (!chk) ans++;
		}
	}
	cout << ans << "\n";

	return 0;
}