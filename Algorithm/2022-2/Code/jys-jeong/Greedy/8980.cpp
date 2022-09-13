#include <bits/stdc++.h>
using namespace std;
int town[2002];
tuple<int, int,int> p[10005];
int n, c, m;
int ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c >> m;
	for (int i = 0; i < m; i++) {
		int from, to, t;
		cin >> from >> to >> t;
		p[i] = { to,from,t };
	}
	sort(p, p + m);
	for (int i = 0; i < m; i++) {
		int from, to, t;
		tie(to, from,t) = p[i];
		bool a = 1;
		for (int j = from; j < to; j++) {
			t = min(t, c - town[j]);
			if (!t) {
				a = false;
				break;
			}
		}
		if (a) {
			ans += t;
			for (int j = from; j < to; j++)	town[j] += t;
		}
	}
	
	cout << ans;
}