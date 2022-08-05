#include <bits/stdc++.h>
using namespace std;

set<int> city;
int n, q;
int l = 1;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			city.insert(i + 1);
		}
	}
	
	while (q--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int m;
			cin >> m;
			if (city.find(m) != city.end()){
				city.erase(m);
			}
			else {
				city.insert(m);
			}
		}
		else if (cmd == 2) {
			int m;
			cin >> m;
			l = (l + m - 1) % n + 1;
		}

		else {
			if (city.empty()) cout << -1 << '\n';
			else if (city.lower_bound(l) != city.end()) {
				cout << *city.lower_bound(l) - l << '\n';
			}
			else {
				int temp = 0;
				if (city.lower_bound(temp) != city.end()) {
					cout << n - l + *city.lower_bound(temp) << '\n';
				}
			}
		}
	}
}