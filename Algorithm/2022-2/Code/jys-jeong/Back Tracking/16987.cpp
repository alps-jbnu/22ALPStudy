#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[9];
int n;
int mx = 0;
int cnt = 0;
void func(int cur) {
	if (cur == n) {
		mx = max(cnt, mx);
		return;
	}
	if (cnt == n - 1 || arr[cur].first <= 0) {
		func(cur + 1);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (cur == i || arr[i].first <= 0)	continue;
		arr[cur].first -= arr[i].second;
		arr[i].first -= arr[cur].second;
		if (arr[cur].first <= 0)		++cnt;
		if (arr[i].first <= 0)	++cnt;
		func(cur + 1);
		if (arr[cur].first <= 0)		--cnt;
		if (arr[i].first <= 0)	--cnt;
		arr[cur].first += arr[i].second;
		arr[i].first += arr[cur].second;
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	func(0);
	cout << mx;
 }