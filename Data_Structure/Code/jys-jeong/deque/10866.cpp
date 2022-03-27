#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	deque<int> de;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push_front") {
			int a;
			cin >> a;
			de.push_front(a);
		}
		else if (s == "push_back") {
			int a;
			cin >> a;
			de.push_back(a);
		}
		else if (s == "pop_front") {
			if (de.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << de.front()<<"\n";
			de.pop_front();
		}
		else if (s == "pop_back") {
			if (de.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << de.back() << "\n";
			de.pop_back();
		}
		else if (s == "size") {
			cout << de.size() << "\n";
		}
		else if (s == "empty") {
			cout << de.empty() << "\n";
		}
		else if (s == "front") {
			if (de.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << de.front() << "\n";
		}
		else if (s == "back") {
			if (de.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << de.back() << "\n";
		}
	}
}