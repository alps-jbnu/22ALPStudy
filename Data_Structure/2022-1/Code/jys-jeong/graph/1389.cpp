#include<bits/stdc++.h>
using namespace std;

vector<int> vec[102];
int board[102][102];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		bool vis[102] = { 0 };
		vis[i] = 1;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int dot = q.front();
			q.pop();
			for (int k : vec[dot]) {
				if (vis[k])	continue;
				vis[k] = 1;
				board[i][k] = board[i][dot]+1;
				q.push(k);
			}
		}
	}
	int sum[102] = { 0 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i] += board[i][j];
		}
	}
	int mn = 99999999;
	for (int i = 1; i <= n; i++) {
		if (mn > sum[i])	mn = sum[i];
	}
	for (int i = 1; i <= n; i++) {
		if (mn == sum[i]) {
			cout << i;
			break;
		}
	}
}