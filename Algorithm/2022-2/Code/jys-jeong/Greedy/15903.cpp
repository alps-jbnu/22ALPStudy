#include <bits/stdc++.h>
using namespace std;


int n, m;
priority_queue<long long, vector<long long>, greater<>> s;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.push(a);
	}
	for (int i = 0; i < m; i++) {
		long long f = s.top();
		s.pop();
		long long e = s.top();
		s.pop();
		s.push(f + e);
		s.push(f + e);
	}
	long long ans = 0;
	
	for (int i = 0; i < n; i++) {
		ans += s.top();
		s.pop();
	}
	cout << ans;
}
