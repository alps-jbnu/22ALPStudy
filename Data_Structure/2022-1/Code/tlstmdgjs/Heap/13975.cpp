#include<bits/stdc++.h>
	using namespace std;
	typedef long long  ll;

	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);

		int T;
		cin >> T;

		while (T--) {
			priority_queue<ll, vector<ll>, greater<ll>> pq;
			int k;
			cin >> k;

			for (int i = 0; i < k; i++) {
				int x;
				cin >> x;
				pq.push(x);
			}

			ll ans = 0;
			while (pq.size() > 1) {
				ll a = pq.top();
				pq.pop();
				ll b = pq.top();
				pq.pop();
				ans += a + b;
				pq.push(a + b);
			}
			cout << ans << "\n";
		}
	}