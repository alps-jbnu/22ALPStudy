#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		string command;
		int temp;
		cin >> command;
		if (command == "push") cin >> temp, st.push(temp);
		else if (command == "pop" && !st.empty()) cout << st.top() << "\n", st.pop();
		else if (command == "size") cout << st.size() << "\n";
		else if (command == "empty") cout << st.empty() << "\n";
		else if (command == "top" && !st.empty()) cout << st.top() << "\n";
		else if (st.empty()) cout << -1 << "\n";
	}
}