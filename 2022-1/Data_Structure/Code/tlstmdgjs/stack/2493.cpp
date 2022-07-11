#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int,int>> s;


	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;

		while (!s.empty()) {
			if (s.top().second > h) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		if (s.empty()) {
			cout << "0" << " ";
		}

		s.push(make_pair(i + 1, h));
	}
	return 0;
}