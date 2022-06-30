#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	stack<int> num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			if (num.empty()) {
				continue;
			}
			num.pop();
		}
		else {
			num.push(a);
		}
	}
	int sum = 0;
	int si = num.size();
	for (int i = 0; i < si;i++) {
		sum += num.top();
		num.pop();
	}
	cout << sum;
}