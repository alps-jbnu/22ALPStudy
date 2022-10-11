#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MAX 10005

int n, m, t;
vector<pair<int, int>> adj[MAX];
priority_queue<tuple<int, int, int>,
	vector<tuple<int, int, int>>,
	greater<tuple<int, int, int>>> pq;
bool chk[MAX];
int cnt;
int ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> t;
	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >>  v >> d;
		adj[u].push_back({ d,v });
		adj[v].push_back({ d,u });
	}
	for (auto nxt : adj[1]) pq.push({ nxt.X,1,nxt.Y });
	chk[1] = 1;
	while (!pq.empty()) {
		if (cnt == n-1) break;
		int cost, a, b;
		tie(cost, a, b) = pq.top(); pq.pop();
		if (chk[b])continue;
		chk[b] = 1;
		ans = ans + cost + t*cnt;
		cnt++;
		for (auto nxt : adj[b]) {
			if (chk[nxt.Y])continue;
			pq.push({ nxt.X,b,nxt.Y });
		}
	}
	if (cnt == n-1) cout << ans;
	else cout << -1;
}