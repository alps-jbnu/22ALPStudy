#include <bits/stdc++.h>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	list<char> l;
	list<char>::iterator c;
	string str;
	cin >> t;

	while (t--) {
		cin >> str;
		l.clear();
		c = l.begin();
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<' && c != l.begin()) {
				c--;
			}
			else if (str[i] == '>' && c != l.end()) {
				c++;
			}
			else if (str[i] == '-' && c != l.begin()) {
				c = l.erase(--c);
			}
			else if (str[i] != '<' && str[i] != '>' && str[i] != '-') {
				l.insert(c, str[i]);
			}
		}

		for (c = l.begin(); c != l.end(); c++) {
			cout << *c;
		}
		cout << '\n';
	}
}