#include <bits/stdc++.h>
using namespace std;

int arr[1005][3];
int n;
int d[1005][3];


int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	d[0][0] = arr[0][0];
	d[0][1] = arr[0][1];
	d[0][2] = arr[0][2];
	for (int i = 1; i < n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + arr[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + arr[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + arr[i][2];
	}
	int ans = min(d[n - 1][0], d[n - 1][1]);
	ans = min(d[n - 1][2], ans);
	cout << ans;
}