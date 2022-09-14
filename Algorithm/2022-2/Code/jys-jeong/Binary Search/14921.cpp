#include<bits/stdc++.h>
using namespace std;


vector<int> vec;

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
	int ans1 = 1000000001;
	int ans2 = 1000000001;
	for (int i = 0; i < n; i++) {
		int st = lower_bound(vec.begin(), vec.end(), -vec[i]) - vec.begin();
		if (st < n && i != st && abs(vec[i] + vec[st]) < abs(ans1 + ans2)) {
			ans1 = vec[i];
			ans2 = vec[st];
		}
		if (st + 1 < n && i != st + 1 && abs(vec[i] + vec[st + 1]) < abs(ans1 + ans2)) {
			ans1 = vec[i];
			ans2 = vec[st + 1];
		}
		if (st != 0 && i != st - 1 && abs(vec[i] + vec[st - 1]) < abs(ans1 + ans2)) {
			ans1 = vec[i];
			ans2 = vec[st - 1];

		}
	}
	cout << ans1 + ans2;
}
