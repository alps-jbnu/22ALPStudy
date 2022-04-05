#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void) {
	deque<int> d;
	int n;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			int a = 0;
			cin >> a;
			d.push_front(a);
		}
		else if (cmd == "push_back") {
			int a = 0;
			cin >> a;
			d.push_back(a);
		}
		else if (cmd == "pop_front") {
			if (!d.empty()) {
				cout << d.front() << '\n';
				d.pop_front();

			}
				
			else
				cout << "-1" << '\n';
		}
		else if (cmd == "pop_back") {
			if (!d.empty()) {
				cout << d.back() << '\n';
				d.pop_back();
			}
			else
				cout << "-1" << '\n';
		}
		else if (cmd == "size") {
			cout << d.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << d.empty() << '\n';
		}
		else if (cmd == "front") {
			if (!d.empty())
				cout << d.front() << '\n';
			else
				cout << "-1" << '\n';
		}
		else if (cmd == "back") {
			if (!d.empty())
				cout << d.back() << '\n';
			else
				cout << "-1" << '\n';
		}
	}
}