#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> p[1000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n);
	pair<int, int> ans = p[0];
	int ans1 = 0;
	for (int i = 1; i < n; i++) {
		if ((p[i].first <= ans.second) && (p[i].second >= ans.second))	ans.second=p[i].second;
		else if (p[i].first>ans.second) {
			ans1 += ans.second - ans.first;
			ans.first = p[i].first;
			ans.second = p[i].second;
		}
	}
	ans1 += ans.second - ans.first;
	cout << ans1;
}
