#include<bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> v1;
		vector<pair<int, int>> v2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			bool c = 0;
			for (auto& k : v1) {
				if (k.first == a) {
					++k.second;
					c = 1;
					break;
				}
			}
			if (!c) {
				v1.push_back({ a,1 });
			}
		}
		for (int i = 0; i < m; i++) {
			int a;
			cin >> a;
			bool c = 0;
			for (auto& k : v2) {
				if (k.first == a) {
					++k.second;
					c = 1;
					break;
				}
			}
			if (!c) {
				v2.push_back({ a,1 });
			}
		}

		sort(v2.begin(), v2.end());
		sort(v1.begin(), v1.end());

		int sz = v1.size();
		int sz1 = v2.size();
		for (int i = 0; i < sz; i++) {
			int a = 0;
			while (a < sz1&&v2[a].first < v1[i].first) {
				cnt += (v2[a].second*v1[i].second);
				a++;
			}
		}
		cout << cnt << '\n';
	}
}
