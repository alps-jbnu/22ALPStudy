#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

vector<int> ch[MAX];
queue<int> q;
int d1[MAX];
int d2[MAX];
int deg[MAX];
int n, m;
int a,b,k;
bool c[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		ch[s].push_back(e);
		deg[e]++;
	}
	cin >> a >> b >> k;
	for (int i = 0; i < k; i++) {
		int can;
		cin >> can;
		c[can] = 1;
	}
	d1[a] = 1;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (c[cur] == 1) d2[cur]++;
		for (auto nxt : ch[cur]) {
			deg[nxt]--;
			if (d2[nxt] < d2[cur]) {
				d1[nxt] = d1[cur];
				d2[nxt] = d2[cur];
			}
			else if(d2[nxt] == d2[cur]){
				d1[nxt] += d1[cur];
			}
			if (deg[nxt] == 0) q.push(nxt);
		}
	}
	cout << d1[b];

}