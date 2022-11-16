#include <bits/stdc++.h>
using namespace std;

int n, m,cnt;
int arr[25];


void func(int num,int cur) {
	if (cur == n) {
		if (num == m)	++cnt;
		return;
	}

	func(num, cur + 1);
	func(num+arr[cur], cur + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0, 0);
	if (m == 0)	--cnt;
	cout << cnt;
}