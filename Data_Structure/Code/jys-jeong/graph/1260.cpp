#include<bits/stdc++.h>
using namespace std;

bool big(int a, int b) {
	return a > b;
}

int main() {
	int n, m,k;
	cin >> n >> m >> k;
	vector<int> vec[10002];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}
	stack<int> st;
	st.push(k);
	bool vis[1002] = { false };
	while (!st.empty()) {
		int dot = st.top();
		st.pop();
		if (vis[dot])	continue;
		vis[dot] = 1;
		cout << dot << " ";
		for (int i = 0; i < vec[dot].size(); i++) {
			int nxt = vec[dot][vec[dot].size() - 1 - i];
			if (vis[nxt])	continue;
			st.push(nxt);
		}
	}
	cout << "\n";
	queue<int> q;
	bool vis1[1002] = { false };
	q.push(k);
	while (!q.empty()) {
		int dot = q.front();
		q.pop();
		if (vis1[dot])	continue;
		vis1[dot] = 1;
		cout << dot << " ";
		for (int c : vec[dot]) {
			if (vis1[c])	continue;
			q.push(c);
			
		}
	}
	cout << "\n";
}