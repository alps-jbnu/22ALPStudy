#include <bits/stdc++.h>
using namespace std;

int n, m, l;
int arr[1005];

int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	arr[n] = 0;
	arr[n + 1] = l;
	sort(arr, arr + n+2);
	int st = 1;
	int en = l;
	int res = 0;
	while (st <= en) {
		int mid = (st + en) / 2;
		int cnt = 0;
		for (int i = 1; i < n+2; i++) {
			int dis = arr[i] - arr[i - 1];

			cnt += dis / mid;
			if (dis % mid == 0)	--cnt;
		}
		if (cnt > m) {
			st = mid + 1;
		}
		else {
			en = mid - 1;
			res = mid;
		}
	}
	cout << res;
}
