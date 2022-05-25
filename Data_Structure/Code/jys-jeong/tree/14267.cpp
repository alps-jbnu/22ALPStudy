#include<bits/stdc++.h>
using namespace std;

vector<int> vec[1000001];
int cnt[100001];
int root;

void dfs(int current) {
	for (int k:vec[current]) {
		cnt[k] += cnt[current];
		dfs(k);
	}
}

 int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a == -1) {
			root = i;
		}
		else {
			vec[a].push_back(i);
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cnt[a] += b;
	}
	dfs(1);

	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << " ";
	}

}
