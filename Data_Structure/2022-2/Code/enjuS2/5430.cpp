#include <bits/stdc++.h>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;


	while (t--) {
		bool r = false;
		bool error = false;
		deque<int> d;
		string p;
		cin >> p;
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		string ss;
		for (int i = 0; i < s.length(); i++) {
			if (isdigit(s[i])) {
				ss += s[i];
			}
			else {
				{
					if (!ss.empty()) {
						d.push_back(stoi(ss));
						ss = "";
					}
				}
			}
		}

		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') {
				if (r) {
					r = false;
				}
				else {
					r = true;
				}
			}
			else {
				if (d.empty()) {
					cout << "error\n";
					error = true;
					break;
				}
				else if (r) {
					d.pop_back();
				}
				else if (!r) {
					d.pop_front();
				}
			}
		}
		if (!error) {
			cout << '[';
		}
		int size = d.size();
		if (r && !d.empty()) {
			for (int i = 0; i < size; i++) {
				cout << d.back();
				if (i != size - 1) {
					cout << ',';
				}
				d.pop_back();
			}
			
		}
		else if (!r && !d.empty()) {
			for (int i = 0; i < size; i++) {
				cout << d.front();
				if (i != size - 1) {
					cout << ',';
				}
				d.pop_front();
			}
		}
		if (!error) {
			cout << "]\n";
		}
	}
}