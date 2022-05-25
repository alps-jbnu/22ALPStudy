#include<bits/stdc++.h>
using namespace std;


vector<int> vec[1002];
int dis[1002][1002];


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(b);
		vec[b].push_back(a);
		dis[a][b] = c;
		dis[b][a] = c;
	}
	
	for (int i = 0; i < m; i++) {
		bool vis[1002] = { false };
		bool flag = 0;
		int to, from,res=0;
		cin >> to >> from;
		queue<int> q;
		queue<int> q1; //거리
		q.push(to);
		q1.push(0);
		vis[to] = 1;
		while (!q.empty()) {
			int cur = q.front();
			int c = q1.front();
			q1.pop();
			q.pop();
			for (int k : vec[cur]) {
				if (vis[k])	continue;
				if (k == from) {
					cout << c + dis[cur][k] << "\n";
					flag = 1;
					break;
				}
				vis[k] = true;
				q.push(k);
				q1.push(c + dis[cur][k]);
				
			}
			if (flag)	break;
		}
	}

}