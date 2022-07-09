#include<bits/stdc++.h>
using namespace std;

vector<int> vec[10002];
int board[10002];
int mx = 0;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		bool vis[10002] = { 0 };
		vis[i] = 1;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int dot = q.front();
			q.pop();
			for (int k : vec[dot]) {
				if (vis[k])	continue;
				vis[k] = 1;
				++board[k];
				q.push(k);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		mx = max(mx, board[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (mx == board[i]) {
			cout << i << " ";
		}
	}
}