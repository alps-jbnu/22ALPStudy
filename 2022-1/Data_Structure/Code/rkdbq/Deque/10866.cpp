#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		string com;
		cin >> com;
		if (com == "push_front") {
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (com == "push_back") {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (com == "size") cout << dq.size() << "\n";
		else if (com == "empty") cout << dq.empty() << "\n";
		else {
			if (dq.empty()) cout << -1 << "\n";
			else {
				if (com == "pop_front") cout << dq.front() << "\n", dq.pop_front();
				else if (com == "pop_back") cout << dq.back() << "\n", dq.pop_back();
				else if (com == "front") cout << dq.front() << "\n";
				else if (com == "back") cout << dq.back() << "\n";
			}
		}
	}
}