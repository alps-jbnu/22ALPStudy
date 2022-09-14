#include <bits/stdc++.h>
using namespace std;

int n;
int arr[52];
int arr1[52];
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	sort(arr, arr + n);
	sort(arr1, arr1 + n, greater<>());
	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans += arr[i] * arr1[i];
	}
	cout << ans;
	
}
