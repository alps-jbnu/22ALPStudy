#include <bits/stdc++.h>
using namespace std;

int arr[10];
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = n - 1;i >=  0; i--) {
		cnt += k / arr[i];
		k = k % arr[i];
	}
	cout << cnt;
}
