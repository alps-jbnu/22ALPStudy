#include <iostream>
using namespace std;
#include<list>
#include<string>

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	string s;
	cin >> t;
	while (t--) {
		list<char> li;
		cin >> s;
		auto c = li.end();
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '<' && c != li.begin()) {
				c--;
			}
			else if (s[i] == '-' && c != li.begin()) {
				c--;
				c = li.erase(c);
			}
			else if (s[i] == '>' && c != li.end()) {
				c++;
			}
			else if (s[i] != '<' && s[i] != '>' && s[i] != '-') {
				li.insert(c, s[i]);
			}
		}
		for (char i: li) cout << i;
		cout << "\n";
	}


}