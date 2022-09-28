#include <bits/stdc++.h>
using namespace std;

int n;
int arr[17][2];
int d[17];


int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = n-1; i >=0; i--) {
		if ((i + arr[i][0]) <= (n )) {
			d[i] = max(d[i + arr[i][0]] + arr[i][1], d[i + 1]);
		}
		else {
			d[i] = d[i + 1];
		}
	}
	cout << *max_element(d, d + n);
}