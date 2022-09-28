#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<int>s;
	long long answer = 0;
	int n;
	cin >> n;

	int a;
	while (n--) {
		cin >> a;
		while (!s.empty()) {
			if (s.top() > a) {
				break;
			}
			else {
				s.pop();
			}
		}
		answer += s.size();
		s.push(a);
	}
	cout << answer;
}