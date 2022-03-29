#include<bits/stdc++.h>
using namespace std;

vector<int> num[1002];
bool vis[1002];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		num[a].push_back(b);
		num[b].push_back(a);
	}
	queue<int> q;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i])	continue;
		q.push(i);
		vis[i]=1;
		++cnt;
		while (!q.empty()) {
			int dot = q.front();
			q.pop();
			for (auto k:num[dot]) {
				if (vis[k])	continue;
				vis[k]=1;
				q.push(k);
			}
		}
		
	}
	cout << cnt;
}