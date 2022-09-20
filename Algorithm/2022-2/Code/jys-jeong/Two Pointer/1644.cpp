#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int cnt = 0;
int arr[4000005];
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 1)	continue;
		for (int j = 2; j <= i * j; j++) {
			if (i * j > n)	break;
			arr[i * j] = 1;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0) {
			v.push_back(i);
		}
	}
	long long ans = 0;
	int en = 0;
	for (int st = 0; st < v.size(); st++) {
		while (en < v.size() && ans < n) {
			ans += v[en];
			++en;
		}
		if (ans == n) {
			++cnt;
		}
		ans -= v[st];
	}
	cout << cnt;
}
