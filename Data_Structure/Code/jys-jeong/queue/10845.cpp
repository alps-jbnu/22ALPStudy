#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> q;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int a;
			cin >> a;
			q.push(a);
		}
		else if (str == "front") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.front() << "\n";
		}
		else if (str == "back") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.back() << "\n";
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "pop") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.front() << '\n';
			q.pop();
		}
		else if (str == "empty") {
			cout << q.empty() << "\n";
		}
	}
}