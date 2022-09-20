#include<bits/stdc++.h>
using namespace std;

unordered_map<string, string> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (n--) {
		string site, password;
		cin >> site >> password;

		s[site] = password;
	}

	while (m--) {
		string findpassword;
		cin >> findpassword;

		cout << s[findpassword] << '\n';
	}

	return 0;
}