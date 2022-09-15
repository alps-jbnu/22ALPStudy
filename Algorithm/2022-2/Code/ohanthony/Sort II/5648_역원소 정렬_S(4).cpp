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
		string num;
		cin >> num;

		reverse(num.begin(), num.end());
		v.push_back(stoll(num)); // stoi: 문자열을 long long로 바꿈
	}

	sort(v.begin(), v.end());
	for (auto nxt : v) cout << nxt << "\n";

	return 0;
}
