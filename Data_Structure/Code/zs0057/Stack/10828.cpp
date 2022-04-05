#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(void) {
	int n;
	cin >> n;
	string cmd;
	stack<int> st;
	int a = 0;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> a;
			st.push(a);
		}
		else if (cmd == "pop") {
			if (!st.empty()) {
				cout << st.top() << '\n';
				st.pop();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (cmd == "size") {
			cout << st.size() << '\n';

		}
		else if (cmd == "empty") {
			if (st.empty()) {
				cout << "1" << "\n";
			}
			else cout << "0" << '\n';
		}
		else if (cmd == "top") {
			if (!st.empty()) {
				cout << st.top() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}

	}
}