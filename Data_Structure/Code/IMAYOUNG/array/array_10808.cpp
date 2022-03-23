#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int a[26] = { 0 };
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 'a']++;
	}

	for (int i = 0; i <= 26; i++) {
		cout << a[i] << " ";
	}

}