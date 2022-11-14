#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> adj[502];
int dist[502];
int n, m; 
int num = 0;

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, e;
		cin >> v >> e;
		adj[v].push_back(e);
		adj[e].push_back(v);
	}
	fill(dist, dist + n+1, -1);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur]) {
			if (dist[nxt] >= 0) continue;
			dist[nxt] = dist[cur]+1;
			if (dist[nxt] >= 3) break;
			q.push(nxt);
			num++;
		}
	}
	cout << num;
}
