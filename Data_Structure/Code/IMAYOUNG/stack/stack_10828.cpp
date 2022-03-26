#include <iostream>
#include <stack>
#include <string>
using namespace std;

//스택 = 프링글스 통!! 
//마지막에 넣은 것만 추가, 빼기가 가능


int main() {
	stack<int> a;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string ch;
		cin >> ch;
		if (ch == "push") {
			int x;
			cin >> x;
			a.push(x);
		}
		else if (ch == "pop") {
			if (a.empty() == 1) {
				cout << -1 << "\n";
			}
			else {
				a.pop();
			}
		}
		else if (ch == "size") {
			cout << a.size() << "\n";
		}
		else if (ch == "empty") {
			cout << a.empty() << "\n";
		}
		else if (ch == "top") {
			{
				if (a.empty() == 1) { //비어있다. 
					cout << -1 << "\n";
				}
				else {
					cout << a.top() << "\n";
				}

			}

		}

	}

}