#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		int n;
		cin >> n;
		deque<int> de;
		char a, b, c;
		cin >> a;
		for (int j = 0; j < n; j++) {
			int g;
			cin >> g;
			de.push_back(g);
			if (j != n - 1) {
				cin >> b;
			}
		}
		cin >> c;
		bool flag = false;
		bool f = false;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'R') {
				flag = !flag;
			}
			else if (str[j] == 'D') {
				if (!de.empty()) {
					if (flag) {
						de.pop_back();
					}
					else if (!flag) {
						de.pop_front();
					}
				}
				else {
					f = true;
					cout << "error\n";
					break;
				}
			}
		}
		if (!f) {
			cout << a;
			if (flag) {
				int si = de.size();
				for (int j= 0;j < si; j++) {
					cout << de.back();
					de.pop_back();
					if (j != si - 1) {
						cout << ",";
					}
				}
			}
			else if (!flag) {
				int si = de.size();
				for (int j = 0; j < si; j++) {
					cout << de.front();
					de.pop_front();
					if (j != si - 1) {
						cout << ",";
					}
				}
			}
			cout << c << "\n";
		}
		
		}

	}