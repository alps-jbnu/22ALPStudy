#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int vis[100005];
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	int en = 0;
	int ans = 0;
	++vis[vec[0]];
	for (int st = 0; st < n; st++) {

		while (en+1 < n&&vis[vec[en+1]]<m) {
			++en;
			++vis[vec[en]];
			
		}
		ans = max(ans, en - st+1);
		--vis[vec[st]];
	}
	cout << ans;
}
