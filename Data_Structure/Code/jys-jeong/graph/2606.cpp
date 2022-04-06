#include<bits/stdc++.h>
using namespace std;

vector<int> vec[102];
bool vis[102];
int cnt = 0;

void dfs(int n) {
	
	for (int k : vec[n]) {
		if (vis[k])	continue;
		++cnt;
		vis[k] = 1;
		dfs(k);
	}
}


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	vis[1] = 1;
	dfs(1);
	cout << cnt;

}
/*#include<bits/stdc++.h>
using namespace std;

vector<int> vec[102];
bool vis[102];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	stack<int> q;
	q.push(1);
	int cnt = 0;
	vis[1] = 1;
	while (!q.empty()) {
		int dot = q.top();
		q.pop();
		for (int k : vec[dot]) {
			if (vis[k])	continue;
			++cnt;
			vis[k] = 1;
			q.push(k);
		}
	}
	cout << cnt;
}
*/