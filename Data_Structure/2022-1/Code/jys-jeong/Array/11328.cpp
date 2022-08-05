#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str1, str2;
		int alph[26] = {0};
		int alph1[26] = { 0 };
		cin >> str1 >> str2;
		for (int j = 0; j < str1.length(); j++) {
			++alph[str1[j] - 'a'];
		}
		for (int j = 0; j < str2.length(); j++) {
			++alph1[str2[j] - 'a'];
		}
		bool got = false;
		for (int j = 0; j < 26; j++) {
			if (alph1[j] != alph[j]) {
				cout << "Impossible\n";
				got = true;
				break;
			}
			continue;
		}
		if (!got) {
			cout << "Possible\n";
		}
	}
}