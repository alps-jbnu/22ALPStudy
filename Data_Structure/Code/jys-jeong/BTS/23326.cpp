#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<int> good;//명소 담는곳

	int n, q, t;
	int peo = 1;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (t == 1)
			good.insert(i);
	}
	for (int i = 0; i < q; i++) {
		int p;
		cin >> p;
		if (p == 1) {
			int nm;
			cin >> nm;
			auto iter = good.find(nm);
			if (iter != good.end())
				good.erase(nm);
				
			else {
				good.insert(nm);
			}

		}
		else if (p == 2) {
			int nm;
			cin >> nm;
			peo = (peo + nm - 1) % n + 1;
		}
		else if (p == 3) {
			if (good.empty())	cout << -1 << "\n";
			else {
				auto iter = good.lower_bound(peo);
				if (iter != good.end()) {
					cout << *iter - peo << '\n';
				}
				else {
					cout << n - peo + *good.begin() << '\n';
				}
			}
		}
	}
}
