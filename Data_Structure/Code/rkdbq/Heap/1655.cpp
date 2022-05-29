#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> Left; //top is median
priority_queue<int, vector<int>, greater<int>> Right;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i{}; i < N; i++) {
		int n;
		cin >> n;

		if (Left.empty()) Left.push(n);
		else if (Left.top() < n) Right.push(n);
		else Left.push(n);

		if (Left.size() < Right.size()) {
			Left.push(Right.top());
			Right.pop();
		}
		else if (Left.size() - 1 > Right.size()) {
			Right.push(Left.top());
			Left.pop();
		}

		cout << Left.top() << "\n";
	}
	return 0;
}