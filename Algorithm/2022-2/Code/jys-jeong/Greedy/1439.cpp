#include <bits/stdc++.h>
using namespace std;

int n;
string s;



int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> s;
	int zero = 0;
	int one = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '0') {
			++zero;
			for (int j = i; j < s.length(); j++) {
				if (s[j] == '0') {
					i = j - 1;
					break;
				}
				
			}
		}
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '1') {
			++one;
			for (int j = i; j < s.length(); j++) {
				if (s[j] == '1') {
					i = j - 1;
					break;
				}
				
			}
		}
	}
	
	cout << min(one, zero);
}
