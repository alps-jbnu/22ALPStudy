#include <iostream>
#include <queue>
using namespace std;

int n, m;
priority_queue<long long, vector<long long>, greater<long long>> cards;
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i{}; i < n; i++) {
		long long card;
		cin >> card;
		cards.push(card);
	}
	for (int i{}; i < m; i++) {
		long long x{ cards.top() };
		//cout << x << " ";
		cards.pop();
		long long y{ cards.top() };
		//cout << y << "\n";
		cards.pop();
		cards.push(x + y);
		cards.push(x + y);
	}
	while (!cards.empty()) {
		ans += cards.top();
		cards.pop();
	}
	cout << ans << "\n";

	return 0;
}