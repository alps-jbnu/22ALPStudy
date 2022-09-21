#include<bits/stdc++.h>
using namespace std;

vector<long long> arr;

int k,n;
bool binary(long long mid) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) { 
		if (arr[i] < mid)	continue;
		cnt += arr[i] - mid;
	}
	return cnt>=k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>k;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		arr.push_back(a);
	}
	
	long long st = 0;
	long long en = 1000000000;
	
	while (st < en) {
		long long mid = (st + en + 1) / 2;
		if (binary(mid))	st = mid;
		else	en = mid - 1;
	}
	cout << st;
}
