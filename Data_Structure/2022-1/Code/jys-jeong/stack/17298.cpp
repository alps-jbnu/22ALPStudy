#include<bits/stdc++.h>
using namespace std;

int ans[1000001];
int main() {
	int n;
	stack<int> a;
	stack<int> big;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push(num);
	}

	for (int i = 0; i < n; i++) {


		for (; !a.empty() &&!big.empty()&&big.top() <= a.top();) {
			big.pop();
		}
		if (big.empty()) {
			ans[n - i-1]=-1;
		}
		else {
			ans[n - i - 1] = big.top();
		}
		big.push(a.top());
		a.pop();

	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}