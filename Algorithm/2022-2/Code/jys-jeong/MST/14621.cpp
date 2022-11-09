#include <bits/stdc++.h>
using namespace std;

int n, m;
char se[1005];
vector<tuple<int, int, int>> vec;
long long res = 0;
vector<int> p(1005,-1);
int find(int x) {
	if (p[x]<0)	return x;
	return p[x] = find(p[x]);
}
bool is_diff_grp(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)	return 0;
	if (p[u] > p[v])	swap(u, v);
	p[u] += p[v];
	p[v] = u;
	return 1;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> se[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ c,a,b });
	}
	int cnt = 0;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < m;i++) {
		int cost, s, e;
		tie(cost, s, e) = vec[i];
		if (se[s] == se[e])	continue;
		if (!is_diff_grp(s, e))	continue;
		res += cost;
		++cnt;
		if (cnt == n - 1)	break;
	}
	if (cnt != n-1) {
		cout << -1;
		return 0;
	}
	cout <<res;

}