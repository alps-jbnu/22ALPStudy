#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
int N, parents[100001];

void dfs(int cur) {
	for (int i{}; i < adj[cur].size(); i++) {
		int nxt = adj[cur][i];
		if (parents[cur] == nxt) continue;
		parents[nxt] = cur;
		dfs(nxt);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i{}; i < N - 1; i++) {
		int u{}, v{};
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i{ 2 }; i <= N; i++) {
		cout << parents[i] << "\n";
	}
	return 0;
}