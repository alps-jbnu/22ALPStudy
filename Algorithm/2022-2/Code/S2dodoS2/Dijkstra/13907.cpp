#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, k;
int S, D;
int pay[30005];
vector<pair<int, int>> adj[1005];
const int INF = 0x3f3f3f3f -1;
vector<pair<int, int>> d;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	cin >> S >> D;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ w,b });
	}
	pay[0] = 0;
	for (int i = 1; i <= k; i++) {
		cin >> pay[i];
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.push({ 0,S,0 });
	while (!pq.empty()) {
		int cur, v, cnt;
		tie(cur, v, cnt) = pq.top(); pq.pop();
		if (v == D) {
			d.push_back({ cnt, cur });
		}
		for (auto nxt : adj[v]) {
			pq.push({ nxt.X + cur,nxt.Y,cnt + 1 });
		}
	}
	for (int i = 0; i <= k; i++) {
		int mini = INF;
		for (int j = 0; j < d.size(); j++) {
			d[j].Y += d[j].X * pay[i];
		}
		for (int j = 0; j < d.size(); j++) {
			mini = min(mini, d[j].Y);
		}
		cout << mini << "\n";
	}
}