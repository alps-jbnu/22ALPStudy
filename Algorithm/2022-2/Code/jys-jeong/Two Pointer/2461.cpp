#include <bits/stdc++.h>
using namespace std;

vector<int> vec[1005];
int n, m;
int mn = INT_MAX;
int res = INT_MAX;
priority_queue <pair<int, pair<int, int>>> pq;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			vec[i].push_back(a);
		}
		sort(vec[i].begin(), vec[i].end(),greater<int>());
		mn = min(mn, vec[i][0]);
		pq.push({ vec[i][0],{i,0} });
	}
	while (1) {
		int a = pq.top().first;
		int b = pq.top().second.first;
		int c = pq.top().second.second;
		pq.pop();
		res = min(res, a - mn);
		if (c == m - 1)	break;
		mn = min(mn, vec[b][c + 1]);
		pq.push({ vec[b][c + 1],{b,c + 1} });

	}
	cout << res;
}
