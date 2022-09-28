#include <bits/stdc++.h>
using namespace std;

int t;
int arr[1000005];
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n;
		vector<int> vec;
		long long ans = 0;
		cin >> n;
		fill(arr, arr + n+2, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int mx = arr[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			if (mx > arr[i]) {
				ans += mx - arr[i];
			}
			else {
				mx = arr[i];
			}
		}
		cout << ans << '\n';
	}
}
