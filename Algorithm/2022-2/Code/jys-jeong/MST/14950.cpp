#include <bits/stdc++.h>
using namespace std;

int n, m,t;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
vector<pair<int, int>> vec[10005];
bool vis[10005];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> t;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	vis[1] = 1;
	for (auto k : vec[1]) {
		pq.push({ k.first,1,k.second });
	}
	int ans=0,cnt = 0;
	int time = 0;
	while (cnt < n - 1) {
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (vis[b])	continue;
		ans += cost+t*(time);
		++time;
		vis[b] = 1;
		++cnt;
		for (auto k : vec[b]) {
			if (!vis[k.second]) {
				pq.push({ k.first,b,k.second });
			}
		}
	}
	cout << ans;

}