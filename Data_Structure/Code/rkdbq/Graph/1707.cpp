#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int K, V, E;
vector<int> lis[20001];
int vis[20001];
int dis[20001];
queue<int> Q;

void init() {
	fill_n(vis, 20001, 0);
	fill_n(dis, 20001, 0);
	for (int i{}; i < 20001; i++) {
		lis[i].clear();
	}
}
void bfs(){
	while (!Q.empty()) {
		int cur{ Q.front() };
		Q.pop();
		if (lis[cur].size() == 0) vis[cur] = -1;
		for (int i{}; i < lis[cur].size(); i++) {
			int nxt{ lis[cur][i] };
			if (vis[nxt] != 0) continue;
			dis[nxt] = dis[cur] + 1;
			if (dis[nxt] % 2 == 1) vis[nxt] = 1;
			else vis[nxt] = -1;
			Q.push(nxt);
		}
	}
}
void printAns() {
	/*for (int i{ 1 }; i <= V; i++) {
		cout << i << " number is  " << vis[i] << "\n";
	}
	cout << "\n";*/
	for (int i{ 1 }; i <= V; i++) {
		for (int j{}; j < lis[i].size(); j++) {
			if (vis[i] == vis[lis[i][j]]) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	for (int j{}; j < T; j++) {
		init();
		cin >> V >> E;
		for (int i{}; i < E; i++) {
			int u, v;
			cin >> u >> v;
			lis[u].push_back(v);
			lis[v].push_back(u);
		}
		for (int i{ 1 }; i <= V; i++) {
			if (vis[i] != 0) continue;
			vis[i] = -1;
			Q.push(i);
			bfs();
		}
		printAns();
	}
	return 0;
}