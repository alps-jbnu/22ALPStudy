#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> adj[100000 + 1000 +1];
int dist[100000 + 1000 + 1];
int arr[1001];
int n, k, m;
int bfs(int cur) {
	dist[cur] = 1;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front(); q.pop();
		
		for (auto nxt : adj[cur]) {
			if (dist[nxt] > -1) continue;
			q.push(nxt);
			if (nxt > 100000)
				dist[nxt] = dist[cur];
			else
				dist[nxt] = dist[cur] + 1;
			if (nxt == n) return dist[nxt];
			
		}
	}
	return -1;
}

int main(void) {
	
	cin >> n >> k >> m;
	int idx = 1;

	while (m--) {
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < k; i++) {
			adj[arr[i]].push_back(100000 + idx);
			adj[100000 + idx].push_back(arr[i]);
		}
		idx++;
	}
	fill(dist, dist + 100000 + 1000 + 1, -1);
	cout << bfs(1) << '\n';
	

}