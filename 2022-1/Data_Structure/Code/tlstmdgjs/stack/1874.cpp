#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	vector<char> result;

	int count = 1;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		while (count <= x) {
			s.push(count);
			count++;
			result.push_back('+');
		}

		if (s.top() == x) {
			s.pop();
			result.push_back('-');
		}

		else {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}