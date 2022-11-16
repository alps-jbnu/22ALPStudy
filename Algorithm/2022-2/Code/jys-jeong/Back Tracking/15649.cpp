#include <bits/stdc++.h>
using namespace std;
bool vis[9];
int n, m;
vector<int> vec;
void dfs(int a, int b) {
	if (b == m) {
		for (int i = 0; i < m; i++) {
			cout << vec[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i])	continue;
		vec.push_back(i);
		vis[i] = 1;
		dfs(i, b + 1);
		vis[i] = 0;
		vec.pop_back();
	}
	
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		vec.push_back(i);
		vis[i] = 1;
		dfs(i, 1);
		vis[i] = 0;
		vec.pop_back();
	}
}