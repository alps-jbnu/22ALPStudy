#include <iostream>
#include <queue>
using namespace std;
pair<int, int> a;

priority_queue<int, vector<int>, greater<int>> pos;
priority_queue<int> neg;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i{}; i < N; i++) {
		int x;
		cin >> x;
		if (x > 0) pos.push(x);
		else if (x < 0) neg.push(x);
		else {
			if (pos.empty() && neg.empty()) cout << "0\n";
			else if (pos.empty()) {
				cout << neg.top() << "\n";
				neg.pop();
			}
			else if (neg.empty()) {
				cout << pos.top() << "\n";
				pos.pop();
			}
			else if (pos.top() >= -neg.top()) {
				cout << neg.top() << "\n";
				neg.pop();
			}
			else
			{
				cout << pos.top() << "\n";
				pos.pop();
			}
		}
	}
	return 0;
}