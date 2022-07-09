#include <bits/stdc++.h>
using namespace std;
pair<int, int> pa[300001];
multiset<int> ms;

int main(void) {
	

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		pa[i] = make_pair(v, m);
	}
	sort(pa, pa + n);
	while (k--) {
		int c;
		cin >> c;
		ms.insert(c);
	}

	long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int m, v;
		v = pa[i].first;
		m = pa[i].second;
		auto it = ms.lower_bound(m);
		if (it == ms.end()) continue;
		ans += v;
		ms.erase(it);
	}
	cout << ans;
}