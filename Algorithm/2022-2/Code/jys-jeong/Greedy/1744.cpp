#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p;
vector<int> m;
int ans = 0;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1)	++ans;
		else if (a <= 0)	m.push_back(a);
		else if (a > 0)	p.push_back(a);
	}
	sort(m.begin(), m.end(), greater<>());
	sort(p.begin(), p.end());
	while (p.size() > 1) {
		ans += *(p.end() - 1) * *(p.end() - 2);
		p.pop_back();
		p.pop_back();
	}
	if (p.size() == 1) {
		ans += p[0];
	}
	while (m.size() > 1) {
		ans += *(m.end() - 1) * *(m.end() - 2);
		m.pop_back();
		m.pop_back();
	}
	if (m.size() == 1) {
		ans += m[0];
	}
	cout << ans;
}
