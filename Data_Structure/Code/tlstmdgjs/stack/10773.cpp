#include<bits/stdc++.h>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> k;
	int sum = 0;

	stack<int>S;
	while (k--) {
		int op;
		cin >> op;

		if (op == 0) {
			S.pop();
		}
		else
			S.push(op);
	}
	while (!S.empty()) {
		sum += S.top();
		S.pop();
	}
	cout << sum;
}