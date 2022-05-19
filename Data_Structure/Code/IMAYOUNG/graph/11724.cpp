#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//dfs로 해보기 

int n, m;
vector<int> adj[1002];
bool visited[1002];
void dfs(int now) {
	visited[now] = 1;
	for (int i = 0; i < adj[now].size(); i++){
		int next = adj[now][i];
		if (!visited[next]) dfs(next);
	}
}


int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int j = 1; j <= n; j++) {
		sort(adj[j].begin(), adj[j].end());
	}
	
	int cnt = 0;
	for (int k = 1; k <= n; k++) {
		if (visited[k]) continue;
		dfs(k);
		cnt++;
	}
	cout << cnt;
}