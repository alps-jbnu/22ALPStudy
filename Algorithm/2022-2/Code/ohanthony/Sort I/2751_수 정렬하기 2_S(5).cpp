#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	while (n--) {
		ll num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	for (auto nxt : v) cout << nxt << "\n";
	return 0;
}
