#include <bits/stdc++.h>
using namespace std;


vector<pair<int, int>> v;
int n;

int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,1 });
		v.push_back({ b,-1 });
	}
	sort(v.begin(), v.end());
	int mx = 0;
	int idx = 0;
	int cnt = 0;
	int ans = 0;
	int c =v[0].first;
	while (1) {
		while (idx < 2 * n && v[idx].first == c) {
			cnt += v[idx].second;
			++idx;
		}
		ans = max(cnt, ans);
		if (idx == 2 * n)	break;
		c = v[idx].first;
	}
	cout << ans;
}
