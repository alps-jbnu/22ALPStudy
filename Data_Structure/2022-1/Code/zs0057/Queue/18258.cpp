#include <iostream>
#include <queue>
#include <string>


void Push(int num) {

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> qu;
	int n;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int i;
			cin >> i;
			qu.push(i);
		}
		else if (cmd == "pop") {
			if (!qu.empty()) {
				cout << qu.front()<< '\n';
				qu.pop();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (cmd == "size") {
			cout << qu.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << qu.empty() << '\n';
		}
		else if (cmd == "front") {
			if (!qu.empty())	cout << qu.front() << '\n';
			else cout << "-1" << '\n';
		}
		else if (cmd == "back") {
			if (!qu.empty()) cout << qu.back() << '\n';
			else cout << "-1" << "\n";
		}
	}
}