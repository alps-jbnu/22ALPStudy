#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 공항에서 입출국을 한다고 생각
int main() {
	queue<int> q;
	int n;
	cin >> n;

	string ch;

	for (int i = 1; i <= n; i++) {
		cin >> ch;
		if (ch == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (ch == "pop") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (ch == "size") {
			cout << q.size() << "\n";
		}
		else if (ch == "empty") {
			cout << q.empty() << "\n";
		}
		else if (ch == "front") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (ch == "back") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}

		}

	}
}
