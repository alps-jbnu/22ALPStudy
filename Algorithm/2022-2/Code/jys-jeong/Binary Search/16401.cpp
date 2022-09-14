#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

int k,n;
bool binary(long long mid) {
	int cnt = 0;
	for (int i = 0; i < k; i++)	cnt +=  arr[i]/mid;
	return cnt>=n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>k;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	
	long long st = 0;
	long long en = 1000000000;
	int mx = 0;
	while (st < en) {
		long long mid = (st + en + 1) / 2;
		if (binary(mid))	st = mid;
		else	en = mid - 1;
	}
	cout << st;
}
