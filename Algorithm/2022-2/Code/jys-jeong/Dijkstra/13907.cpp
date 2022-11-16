#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[1005];
int n, m,k,st,en;
priority_queue<tuple<int,int, int>, vector<tuple<int,int, int>>, greater<>> q;
int dis[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m>>k>>st>>en;	
	for (int i = 0; i < m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		v[from].push_back({ weight,to });
		v[to].push_back({ weight,from });
	}

	q.push({ 0,st,0 });
	int mx = INT_MAX / 2;
	for (int i = 1; i <= n; i++) {
		fill(dis[i], dis[i] + n + 2, mx);
	}
	fill(dis[1], dis[1] + n + 2, 0);
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.top();
		q.pop();
		if (dis[b][c] < a)	continue;
		for (auto nxt : v[b]) {
			if (dis[nxt.second][c+1] > a + nxt.first) {
				dis[nxt.second][c + 1] = a + nxt.first;
				q.push({ a + nxt.first,nxt.second,c + 1 });
			}
		}
	}
	int mn = INT_MAX;
	for (int i = 0; i <= n; i++) {
		mn = min(dis[en][i], mn);
	}

	cout << mn << '\n';
	int sm = 0;
	for (int i = 0; i < k; i++) {
		int a,mx=INT_MAX;
		cin >> a;
		sm += a;

		for (int j = 0; j <= n; j++) {
			mx=min(mx, dis[en][j]+sm*j);
		}
		cout << mx << '\n';
	}
	
	

	
}