#include <bits/stdc++.h>
using namespace std;

long long arr[2005];
int n;
vector<long long> vec;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bool z = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			z = 0;
			break;
		}
	}
	if (z) {
		cout << n;
		return 0;
	}
	sort(arr, arr + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j =0; j < n; j++) {
			if (i == j)	continue;
			
			int st = lower_bound(arr, arr + n, arr[i]-arr[j]) - arr;
			if (st == i||st==j)	continue;
			if ( arr[st]+arr[j]==arr[i]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}