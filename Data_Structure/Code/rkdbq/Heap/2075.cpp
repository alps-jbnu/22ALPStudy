#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i{}; i < N * N; i++) {
		int n;
		cin >> n;
		if (pq.size() < N)	pq.push(n);
		else if (pq.top() < n) {
			pq.pop();
			pq.push(n);
		}
	}
	
	cout << pq.top() << "\n";

	return 0;
}