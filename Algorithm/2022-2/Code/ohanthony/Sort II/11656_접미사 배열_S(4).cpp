#include<bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		v.push_back(s.substr(i, s.length()));
	}

	sort(v.begin(), v.end());
	for (auto nxt : v) cout << nxt << "\n";
	return 0;
}
