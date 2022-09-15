#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
vector<int> vec;


int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	cin >> m;
	sort(vec.begin(), vec.end());
	int st = 0;
	int en = vec[n - 1];
	int ans = 0;
	while (st <= en) {
		int mid = (st + en) / 2;
		int sm = 0;
		for (int i = 0; i < n; i++) {
			sm += min(mid, vec[i]);
		}
		if (m>=sm) {
			st= mid + 1;
			ans = mid;
		}
		else {
			en = mid - 1;
		}
	}
	cout << ans;
}
