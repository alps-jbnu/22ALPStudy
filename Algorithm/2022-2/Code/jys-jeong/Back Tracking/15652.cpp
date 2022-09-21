#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

void func(int cur,int num) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++) {
		v.push_back(i);
		func(cur+1,i);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		func(1,i);
		v.pop_back();
	}
}