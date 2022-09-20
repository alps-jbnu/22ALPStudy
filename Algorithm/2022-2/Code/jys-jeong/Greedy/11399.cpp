#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1002];
int sm[1002];
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	sm[0] = arr[0];
	for (int i = 1; i < n; i++) {
		sm[i] += arr[i] + sm[i - 1];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += sm[i];
	}
	cout << ans;
	
}
