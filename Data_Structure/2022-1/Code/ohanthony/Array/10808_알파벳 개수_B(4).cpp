#include<bits/stdc++.h>
using namespace std;

int alpha[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		alpha[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << ' ';
	}
	return 0;
}