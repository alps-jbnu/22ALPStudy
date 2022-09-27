#include <iostream>
#include <string>
using namespace std;
int N[10000];
int pos = 0;

int main(void) {
	int t;
	cin >> t;
	string s;
	int a;
	for (int i = 0; i < t; i++) {
		cin >> s;
		if (s == "push") {
			cin >> a;
			N[pos] = a;
			pos++;
		}
		else if (s == "pop") {
			if (pos != 0) pos--;
			if (N[0] == 0) cout << -1 << '\n';
			else {
				cout << N[pos] << '\n';
				N[pos] = 0;
			}
		}
		else if (s == "size") {
			cout << pos << '\n';
		}
		else if (s == "empty") {
			if (N[0] == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "top") {
			if (N[0] == 0) cout << -1 << '\n';
			else cout << N[pos - 1] << '\n';
		}
	}

	return 0;
}