#include<bits/stdc++.h>
using namespace std;

int a[26], b[26];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s1, s2;
	bool occur = true;

	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		for (int i = 0; i < s1.length(); i++) {
			a[s1[i] - 'a']++;
			b[s2[i] - 'a']++;
		}
		occur = true;
		
		for (int i = 0; i < 26; i++) {
			if (a[i] != b[i]) {
				occur = false;
				break;
			}
		}
		if (occur)
			cout << "Possible" << '\n';
		else
			cout << "Impossible" << '\n';

		for (int i = 0; i < 26; i++) {
			a[i] = 0;
			b[i] = 0;
		}
	}
}