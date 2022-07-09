#include <iostream>
#include <string>
using namespace std;
#include <deque>

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> d;

	int n;
	cin >> n;
	string ch;

	for (int i = 1; i <= n; i++) {
		cin >> ch;
		if (ch == "push_front") {
			int t;
			cin >> t;
			d.push_front(t);
		}
		else if (ch == "push_back") {
			int t;
			cin >> t;
			d.push_back(t);
		}
		else if (ch == "pop_front") {
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.front() << "\n";
				d.pop_front();
			}
		}
		else if (ch == "pop_back") {
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.back() << "\n";
				d.pop_back();
			}

		}
		else if (ch == "size") {
			cout << d.size() << "\n";
		}
		else if (ch == "empty") {
			cout << d.empty() << "\n";
		}
		else if (ch == "front") {
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.front() << "\n";
			}
		}
		else if (ch == "back") {
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.back() << "\n";
			}
		}
	}
}