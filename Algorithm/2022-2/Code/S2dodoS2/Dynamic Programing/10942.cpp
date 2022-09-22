#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[2005];
bool d[2005][2005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i][i] = 1;
	}
	for (int i = 1; i <= n-1; i++) {
		if (arr[i] == arr[i + 1]) d[i][i + 1] = 1;
	}
	for (int i = 2; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (d[j + 1][j + i - 1] == 1 && arr[j] == arr[j + i]) d[j][j + i] = 1;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << d[s][e] << "\n";
	}
	
}