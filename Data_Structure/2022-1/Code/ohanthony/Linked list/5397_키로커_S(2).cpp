#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		string password;
		cin >> password;

		list<char> l = {};
		auto cursor = l.end();

		for (int i = 0; i < password.length(); i++) {
			if (password[i] == '<') {
				if (cursor != l.begin()) cursor--;
			}
			else if (password[i] == '>') {
				if (cursor != l.end()) cursor++;
			}
			else if (password[i] == '-') {
				if (cursor != l.begin()) { // 커서 바로 앞에 글자가 존재하면, 그 글자 지움
					cursor--;
					cursor = l.erase(cursor);
				}
			}
			else l.insert(cursor, password[i]);
		}

		for (auto i : l) {
			cout << i;
		}
		cout << "\n";
	}

	return 0;
}

