#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> arr[100005];
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr, arr + n);
	int t = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (t > arr[i].second)	continue;
		cnt++;
		t = arr[i].first;
	}
	cout << cnt;
}
