#include<bits/stdc++.h>
using namespace std;



int arr[100005];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int a = 1000000001;
	int b = 1000000001;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(arr, arr + n, -arr[i]) - arr;
		if (idx + 1 < n && i != idx + 1 && abs(arr[i] + arr[idx + 1]) < abs(a + b)) {
			a = arr[i];
			b = arr[idx + 1];
		}
		if (idx < n && i != idx && abs(arr[i] + arr[idx]) < abs(a + b)) {
			a = arr[i];
			b = arr[idx];
		}
		
		if (idx != 0 && i != idx - 1 && abs(arr[i] + arr[idx - 1]) < abs(a + b)) {
			a = arr[i];
			b = arr[idx - 1];
		}
	}
	if (a > b)	swap(a, b);
	cout << a << ' ' << b;
}
