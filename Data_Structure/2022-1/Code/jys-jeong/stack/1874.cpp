#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	stack<int> a;
	string str = "";
	int num[100001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		a.push(i);
		str += '+';
		if(num[idx]==a.top()){
			if (a.empty()) {
				cout << "NO";
				return 0;
			}
			for (;!a.empty();) {
				if (num[idx] == a.top()) {
					a.pop();
					str += '-';
					++idx;
				}
				else {
					break;
				}
			}
		}
	}
	if (a.empty()) {
		for (int i = 0; i < str.length(); i++) {
			cout << str[i] << "\n";
		}
	}
	else {
		cout << "NO";
	}
}