#include <bits/stdc++.h>
using namespace std;

int n;
long long s;
vector<int> vec;


int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	long long ans = 0;
	int en = 0;
	int g=0x7fffffff;
	for (int st = 0; st < n; st++) {
		while (en < n && ans < s) {
			ans += vec[en];
			++en;
		}
		if(ans>=s)
			g = min(en - st ,g);
		ans -= vec[st];

	}
	if (g == 0x7fffffff) {
		cout << 0;
		return 0;
	}
	cout << g;
}

