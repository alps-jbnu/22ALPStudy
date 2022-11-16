#include<bits/stdc++.h>
using namespace std;

vector<int> adj[20005];
int house[20005];
int result; // 헛간까지의 거리

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	queue<int> q;
	q.push(1);
	house[1] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (auto nxt : adj[cur]) {
			if (house[nxt]) continue;

			q.push(nxt);
			house[nxt] = house[cur] + 1;
			result = max(result, house[nxt]);
		}
	}

	int index = 99999;  // 가장 작은 헛간의 번호를 저장할 변수
	int count = 0; // 헛간과 같은 거리를 갖는 헛간의 개수
	for (int i = 1; i <= n; i++) {
		if (house[i] == result) {
			count++;
			index = min(index, i);
		}
	}

	cout << index << ' ' << result - 1 << ' ' << count;
	return 0;
}