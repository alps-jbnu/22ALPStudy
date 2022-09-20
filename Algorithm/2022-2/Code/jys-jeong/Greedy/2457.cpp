#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> vec;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vec.push_back({ a * 100 + b,c * 100 + d });
	}
	int t = 301;
	int ans = 0;
	sort(vec.begin(), vec.end());
	while (t < 1201) {
		int nxt = t;
		for (int i = 0; i < n; i++) {
			if (vec[i].first <= t && vec[i].second > nxt) {
				nxt = vec[i].second;
			}
		}
		if (t == nxt) {
			cout << 0;
			return 0;
		}
		++ans;
		t = nxt;
	}
	cout << ans;
	
}
