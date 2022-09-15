#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n,m;
long long d[1000005];


int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + arr[i];
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << d[b] - d[a - 1]<<'\n';
	}
	
}