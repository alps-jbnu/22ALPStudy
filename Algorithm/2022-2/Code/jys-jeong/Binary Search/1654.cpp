#include<bits/stdc++.h>
using namespace std;

int arr[10005];
int k,n;

bool bi(long long mid) {
	int cnt = 0;
	for (int i = 0; i < k; i++)	cnt += arr[i] /mid;
	return cnt >= n;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>k>> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	long long st = 0;
	long long en = 0x7fffffff;
	while (st < en) {
		long long mid = (st + en+1) / 2;
		if (bi(mid))	st = mid;
		else {
			en = mid - 1;
		}
	}
	cout << st;
}
