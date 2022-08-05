#include <iostream>
#include <vector>
using namespace std;

int n, m;
int I, W;
vector<int> adj[100001];
int parent[100001];
int w[100001];
int ans[100001];

void dfs(int cur, int bef) {

	ans[cur] += ans[bef] + w[cur];

	for (int i{}; i < adj[cur].size(); i++) {
		int nxt{ adj[cur][i] };
		if (nxt == bef) continue;
		dfs(nxt, cur);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i{ 1 }; i <= n; i++) {
		cin >> parent[i];
		if (i > 1) { //1 is boss
			adj[parent[i]].push_back(i);
			adj[i].push_back(parent[i]);
		}
	}
	for (int i{}; i < m; i++) {
		cin >> I >> W;
		w[I] += W; //한 사람이 중복 칭찬 받을 수 있음
	}
	dfs(1, -1);
	for (int i{ 1 }; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}