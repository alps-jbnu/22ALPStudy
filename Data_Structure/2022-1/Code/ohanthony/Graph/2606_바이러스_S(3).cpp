#include<bits/stdc++.h>
using namespace std;

vector<int> com[105];
bool vis[105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		com[a].push_back(b);
		com[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	vis[1] = true;

	int result = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (auto nxt : com[cur]) {
			if (vis[nxt]) continue;

			q.push(nxt);
			vis[nxt] = true;
			result++;
		}
	}

	cout << result;
	return 0;
}
