#include<bits/stdc++.h>
using namespace std;


int main() {
	int k;
	int n, m;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n >> m;
		vector<int> vec[20002];
		int board[20002] = { 0 };
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (board[i] != 0)	continue;
			queue<int> q;
			q.push(i);
			board[i] = 1;
			while (!q.empty()) {
				int dot = q.front();
				q.pop();
				for (int k : vec[dot]) {
					if (board[k] != 0)	continue;
					board[k] = board[dot] * -1;
					q.push(k);
				}
			}
		}
		bool flag = 0;
		for (int i = 1; i <= n; i++) {
			int siz = vec[i].size();
			for (int j = 0; j < siz; j++) {
				if (board[i] == board[vec[i][j]]) {
					flag = 1;
				}
			}
		}
		if (flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}