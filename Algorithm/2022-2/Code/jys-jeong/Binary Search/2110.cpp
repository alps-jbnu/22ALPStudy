#include <bits/stdc++.h>
using namespace std;

int n, c;
long long arr[200005];

int ans = 0;


int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long st=1;
	long long en =arr[n-1];
	while (st <= en) {
		long long mid = (st + en) / 2;
		int cnt = 1;
		int p = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] - p >= mid) {
				++cnt;
				p = arr[i];
			}
		}
		if (cnt >= c) {
			st = mid + 1;
			ans = max(ans, (int)mid);
		}
		else {
			en = mid - 1;
		}
	}
	
	cout << ans;
}