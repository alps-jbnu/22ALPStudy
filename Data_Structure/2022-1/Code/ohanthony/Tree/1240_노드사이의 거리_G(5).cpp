#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, a, b, len;
vector<pair<int, int>> adj[1005];
int length[1005];

void bfs(int start, int end) {
	fill(length, length + 1005, -1);
	queue<int> q;
	q.push(start);
	length[start] = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (auto nxt : adj[cur]) {
			if (length[nxt.X] > -1) continue;

			length[nxt.X] = length[cur] + nxt.Y;
			q.push(nxt.X);
		}
	}
	cout << length[end] << "\n";
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> len;
		adj[a].push_back({ b, len });
		adj[b].push_back({ a, len });
	}

	while (m--) {
		int x, y;
		cin >> x >> y;
		bfs(x, y);
	}
	return 0;
}
