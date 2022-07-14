#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100001];
bool visited[100001];
bool cycle[100001];
int n, m, cnt1, cnt2 = 0;	//n:뉴런의 개수 m:시냅스의 개수, cnt1:연결요소의 개수, cnt2:사이클의 개수

void dfs(int cur, int p) {
	visited[cur] = true;
	for (int nxt : adj[cur]) {
		if (!visited[nxt])
			dfs(nxt, cur);
		else if (!cycle[nxt] && nxt != p)
			cnt2++;
	}
	cycle[cur] = true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, 0);
			cnt1++;
		}
	}
	cout << cnt1 - 1 + cnt2;
	return 0;
}