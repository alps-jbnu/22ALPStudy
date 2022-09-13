#include <bits/stdc++.h>
using namespace std;

int n;
long long arr1[4005];
long long arr2[4005];
long long arr3[4005];
long long arr4[4005];
vector<long long> v1;
vector<long long> v2;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i] >> arr2[i] >> arr3[i] >> arr4[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v1.push_back(arr1[i] + arr2[j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v2.push_back(arr3[i] + arr4[j]);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	long long cnt = 0;
	for (int i = 0; i < v1.size(); i++) {
		long long st = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		long long en = upper_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		cnt += en - st;
	}
	cout << cnt;
}