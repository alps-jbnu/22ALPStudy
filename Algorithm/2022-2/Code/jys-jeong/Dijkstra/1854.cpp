#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[1005];

int n, m,k;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
priority_queue<int> dis1[1005];
int dis[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m>>k;
	
	
	
	for (int i = 0; i < m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		v[from].push_back({ weight,to });
		
	}
	q.push({ 0,1 });
	dis1[1].push(0);

	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		for (auto nxt : v[cur.second]) {
			if (dis1[nxt.second].size() < k) {
				dis1[nxt.second].push(nxt.first + cur.first);
				q.push({ nxt.first + cur.first,nxt.second });
			}
			else {
				if (dis1[nxt.second].top() > nxt.first + cur.first) {
					dis1[nxt.second].pop();
					dis1[nxt.second].push(nxt.first + cur.first);
					q.push({ nxt.first + cur.first ,nxt.second });
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dis1[i].size() < k)	cout << "-1\n";
		else {
			cout << dis1[i].top() << '\n';
		}
	}
	
	

	
}