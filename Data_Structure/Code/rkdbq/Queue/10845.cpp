#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		string com;
		cin >> com;
		if (com == "push") {
			int input;
			cin >> input;
			q.push(input);
		}
		else if (com == "empty") cout << q.empty() << "\n";
		else if (com == "size") cout << q.size() << "\n";
		if (q.empty()) {
			if (com == "pop") cout << -1 << "\n";
			else if (com == "front") cout << -1 << "\n";
			else if (com == "back") cout << -1 << "\n";
		}
		else {
			if (com == "pop") cout << q.front() << "\n", q.pop();
			else if (com == "front") cout << q.front() << "\n";
			else if (com == "back") cout << q.back() << "\n";
		}
	}
}