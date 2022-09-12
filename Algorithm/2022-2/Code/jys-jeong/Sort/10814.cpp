#include<bits/stdc++.h>
using namespace std;

pair<int, string> arr[100005];

int n;
bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	stable_sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++) {
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	}
}
