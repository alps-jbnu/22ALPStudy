#include <bits/stdc++.h>
using namespace std;

int n,m,k,l;
vector<int> vec;
int ans = 0;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n>>m>>k>>l;
	vec.resize(2 * n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec[i] = a;
		vec[i + n] = a;
	}
	for (int st = 0; st < n; st++) {
		bool vis[3005] = { false };
		int cnt = 0;
		int c = 1;
		for (int en = st; en < st + k; en++) {
			if (!vis[vec[en]]) {
				vis[vec[en]] = 1;
			}
			else {
				++cnt;
			}
		}
		if (vis[l])	c = 0;
		ans = max(ans, k - cnt + c);
		
	}
	
	cout << ans;
	
	
}
