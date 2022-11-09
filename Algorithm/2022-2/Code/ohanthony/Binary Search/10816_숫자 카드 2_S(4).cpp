#include<bits/stdc++.h>
using namespace std;

int arr[500005];
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;
		cout << upper_bound(arr, arr + n, target) - lower_bound(arr, arr+n, target) << ' ';
	}
	return 0;
}