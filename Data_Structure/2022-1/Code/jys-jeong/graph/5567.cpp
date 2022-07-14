#include<bits/stdc++.h>
using namespace std;

vector<int> vec[502];
bool vis[502];
int cnt = 0;
void dfs(int n, int a) {
	if (a >= 2)	return;
	for (int k : vec[n]) {
		if (n == 1 && vis[k]) { 
			vis[k] = 0; 
			--cnt;
		}
		if (vis[k])	continue;
		vis[k] = 1;
		++cnt;
 		dfs(k,a+1);
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
	dfs(1,0);
	cout << cnt;
}