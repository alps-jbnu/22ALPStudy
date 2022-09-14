#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
vector<int> ans;
int lower_idx(int t, int len) {
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st + en) / 2;
		if (vec[mid] >= t)	en = mid;
		else//t가 mid보다 크면
		{
			st = mid + 1;
		}
	}
	return st;
}
int upper_idx(int t, int len) {
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st + en) / 2;
		if (vec[mid] > t)	en = mid;
		else {//t가 mid보다 크거나 같으면
			st = mid + 1;
		}
	}
	return st;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	int m;
	cin >> m;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		ans.push_back(upper_idx(a, n) - lower_idx(a, n));
 	}
	for (int k : ans) {
		cout << k << ' ';
	}
}
