#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	for (ll i = 0; i < n * n; i++) {
		ll num;
		cin >> num;
		pq.push(num);

		if (pq.size() > n) pq.pop();
	}

	cout << pq.top();
	return 0;
}
