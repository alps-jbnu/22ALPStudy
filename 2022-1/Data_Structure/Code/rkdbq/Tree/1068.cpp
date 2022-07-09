#include <iostream>
#include <vector>
using namespace std;

int N, parent[51], del, ans;
vector<int> adj[51];

void dfs(int cur, int bef) {
	for (int i{}; i < adj[cur].size(); i++) {
		int nxt{ adj[cur][i] };
		if (bef == nxt) {
			if (adj[cur].size() == 1) ans++;
			continue;
		}
		dfs(nxt, cur);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	int root{};
	for (int i{}; i < N; i++) {
		cin >> parent[i];
		if (parent[i] == -1) root = i;
	}
	cin >> del;
	parent[del] = -2;
	for (int i{}; i < N; i++) {
		if (parent[i] >= 0 && parent[i] != del) {
			adj[i].push_back(parent[i]);
			adj[parent[i]].push_back(i);
		}
	}
	dfs(root, -1);
	if (ans == 0 && parent[root] != -2) cout << ans + 1; //root node의 child node가 del일 경우 예외 처리
	else cout << ans;
	return 0;
}