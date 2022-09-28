#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int n;
int d[1005];


int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	d[0] = 1;
	d[1] = 2;
	for (int i = 2; i < n; i++) {
		d[i] = (d[i - 1] + d[i - 2])%10007;
	}
	cout << d[n - 1];
}