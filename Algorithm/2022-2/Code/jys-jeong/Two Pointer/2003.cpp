#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
int arr[100005];
int cnt = 0;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long ans = 0;
	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && ans < m) {
			ans += arr[en];
			++en;
		}
		if (ans == m)	++cnt;
		ans -= arr[st];
	}
	cout << cnt;
}
