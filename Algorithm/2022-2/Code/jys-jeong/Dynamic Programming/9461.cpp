#include <bits/stdc++.h>
using namespace std;

int n;
int arr[105];
long long d[105];


int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	for (int i = 4; i <= 100; i++) {
		d[i] = d[i - 2] + d[i - 3];
	}
	while (t--) {
		cin >> n;
		cout << d[n] << '\n';
	}
	
	
}