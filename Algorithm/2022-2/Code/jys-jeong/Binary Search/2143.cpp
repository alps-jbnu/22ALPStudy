#include <bits/stdc++.h>
using namespace std;
long long t;
int n,m;
long long arr1[1005];
long long arr2[1005];
vector<long long> v1;
vector<long long> v2;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	v1.push_back(arr1[0]);
	for (int i = 1; i < n; i++) {
		v1.push_back(v1[i - 1] + arr1[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			v1.push_back(v1[i] - v1[j]);
		}
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	v2.push_back(arr2[0]);
	for (int i = 1; i < m; i++) {
		v2.push_back(v2[i - 1] + arr2[i]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i; j++) {
			v2.push_back(v2[i] - v2[j]);
		}
	}
	long long cnt = 0;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (auto k : v1) {
		auto s = t - k;
		auto st = lower_bound(v2.begin(), v2.end(), s) - v2.begin();
		auto en = upper_bound(v2.begin(), v2.end(), s) - v2.begin();
		cnt += en - st;
	}
	cout << cnt;
}