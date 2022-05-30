#include <iostream>
#include <queue>
using namespace std;
pair<int, int> a;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i{}; i < N; i++) {
		int x;
		cin >> x;
		if (pq.empty() && x == 0) cout << "0\n";
		else if (x == 0) {
			cout << pq.top() << "\n";
			pq.pop();
		}

		else if (x > 0) pq.push(x);
	}
	return 0;
}