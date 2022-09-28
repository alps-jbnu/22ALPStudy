#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[1000005];
long long cnt = 0;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n>>k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int oddcnt = 0;
	int ans = 0;
	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && oddcnt <= k) {
			if (arr[en]%2!=0) {
				++oddcnt;
			}
			++en;
		}
		ans = max(en - st - oddcnt, ans);
		if (arr[st]%2!=0) {
			--oddcnt;
		}
	}
	cout << ans;
}
