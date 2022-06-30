#include<bits/stdc++.h>
using namespace std;

vector<int> vec[20002];
int board[20002];
int mx = 0;
bool vis[20002];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	queue<pair<int,int>> q;
	q.push({ 1, 0});
	vis[1] = 1;
	while (!q.empty()) {
		auto dot = q.front();
		q.pop();
		for (int k : vec[dot.first]) {
			if (vis[k])	continue;
			vis[k] = 1;
			board[k] = dot.second + 1;
			q.push({ k,dot.second + 1 });
		}
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, board[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (mx == board[i]) {
			cout << i << " "<<mx<<" ";
			break;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (mx == board[i]) {
			++cnt;
		}
	}
	cout << cnt;
}