#include <bits/stdc++.h>
using namespace std;
 
vector<int> a[101];
bool check[101];
int cnt = 0;

void dfs(int x) {
	check[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (!check[y]) {
			dfs(y);
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
    	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(1);
	cout << cnt << '\n';
}