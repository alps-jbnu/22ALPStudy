#include<bits/stdc++.h>
using namespace std;

vector<int> heavy[102];
vector<int> light[102];
int a = 0;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		heavy[a].push_back(b);
		light[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		queue<int> q;
		q.push(i);
		bool vis[102] = { false };
		int cnt = 0;
		while (!q.empty()) {
			int dot = q.front();
			q.pop();
			vis[dot] = 1;

			for (int k : heavy[dot]) {
				if (vis[k])	continue;
				++cnt;
				vis[k] = 1;
				q.push(k);
			}
		}
		if (cnt >= (n + 1) / 2)
			++a;
	}
	for (int i = 1; i <= n; i++) {
		queue<int> q;
		q.push(i);
		int cnt = 0;
		bool vis[102] = { false };
		while (!q.empty()) {
			int dot = q.front();
			q.pop();
			vis[dot] = 1;
			for (int k : light[dot]) {
				if (vis[k])	continue;
				++cnt;
				vis[k] = 1;
				q.push(k);
			}
		}
		if (cnt >= (n + 1) / 2)
			++a;
	}
	
	cout << a;
}