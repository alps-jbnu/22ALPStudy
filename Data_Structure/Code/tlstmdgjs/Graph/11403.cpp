#include <bits/stdc++.h>
using namespace std;

vector<int>adj[101];
int vis[101];

void dfs(int cur) {
	stack<int>s;
	for (int i = 0; i < adj[cur].size(); i++) {
		if (!vis[adj[cur][i]]) {
			vis[adj[cur][i]] = 1;
			dfs(adj[cur][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int p;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p;
			if (p==1)
				adj[i].push_back(j);
		}
	}
	for (int i = 0; i < n; i++) {
		memset(vis, 0, sizeof(vis));
		dfs(i);
		for (int j = 0; j < n; j++)
			cout << vis[j] << " ";
		cout << "\n";
	}
}