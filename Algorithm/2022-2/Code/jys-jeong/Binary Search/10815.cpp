#include<bits/stdc++.h>
using namespace std;

int arr[500005];
int f[500005];
int k,n;




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		cout << binary_search(arr, arr + n, a)<<' ';
	}
}
