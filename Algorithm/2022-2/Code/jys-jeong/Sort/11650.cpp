#include<bits/stdc++.h>
using namespace std;

pair<int, int> arr[100005];

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	stable_sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	}
}
