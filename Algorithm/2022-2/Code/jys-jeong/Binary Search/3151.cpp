#include<bits/stdc++.h>
using namespace std;



int arr[100005];
int n;
vector<int> vec;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	long long cnt = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int sm = arr[i] + arr[j];
			int st = lower_bound(arr+j+1, arr + n, -sm) - arr;
			int en = upper_bound(arr+j+1, arr + n, -sm) - arr;
			cnt += en - st;
		}
	}
	
	
	cout << cnt;
}
