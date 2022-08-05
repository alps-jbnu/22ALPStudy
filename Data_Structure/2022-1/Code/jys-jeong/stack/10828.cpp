#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	stack<int> num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		if (a == "push") {
			int ge;
			cin >> ge;
			num.push(ge);
		}
		else if (a == "pop") {
			if (num.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << num.top()<<"\n";
			num.pop();
		}
		else if (a == "size") {
			cout << num.size()<<"\n";
		}
		else if (a == "empty") {
			cout << num.empty() << "\n";
		}
		else if (a == "top") {
			if (num.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << num.top() << "\n";
		}
	}
}