#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	int cnt = 0;
	int num[10] = { 0 };
	cin >> str;
	for (int i = 0; i < str.length();i++) {
		++num[str[i]-'0'];
	}
	num[6] += num[9];
	if (num[6] % 2 == 1) {
		++num[6];
	}
	num[6] /= 2;
	for (int i = 0; i < 9; i++) {
		cnt = max(cnt, num[i]);
	}
	cout << cnt;
}