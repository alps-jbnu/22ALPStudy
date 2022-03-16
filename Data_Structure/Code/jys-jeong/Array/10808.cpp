#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	int cnt[26] = { 0 };
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		++cnt[str[i] - 'a'];
	}
	for (int i = 0; i < 26; i++) {
		cout << cnt[i] << " ";
	}
}