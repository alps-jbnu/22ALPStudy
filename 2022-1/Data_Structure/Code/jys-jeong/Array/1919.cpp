#include<bits/stdc++.h>
using namespace std;


int main() {

		string str1, str2;
		int alph[26] = {0};
		int alph1[26] = { 0 };
		int cnt = 0;
		cin >> str1 >> str2;
		for (int j = 0; j < str1.length(); j++) {
			++alph[str1[j] - 'a'];
		}
		for (int j = 0; j < str2.length(); j++) {
			++alph1[str2[j] - 'a'];
		}
		for (int j = 0; j < 26; j++) {
			if (alph1[j] != alph[j]) {
				int a = alph1[j] > alph[j] ? alph1[j] - alph[j] : alph[j] - alph1[j];
				cnt += a;
			}
		}
		cout << cnt;
}