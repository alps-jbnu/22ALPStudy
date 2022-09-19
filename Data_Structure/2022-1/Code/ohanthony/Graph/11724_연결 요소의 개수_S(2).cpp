#include<bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;

		result++;
		vis[i] = true;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (auto nxt : v[cur]) {
				if (vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
			}
		}
	}

	cout << result;
	return 0;
}
