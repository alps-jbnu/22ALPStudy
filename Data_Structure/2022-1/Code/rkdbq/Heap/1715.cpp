#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> cards;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i{}; i < N; i++) {
		int bundle;
		cin >> bundle;
		cards.push(bundle);
	}

	while (true) {
		if (cards.size() < 2) break;

		int bindTwoBundles{};

		bindTwoBundles += cards.top();
		cards.pop();
		bindTwoBundles += cards.top();
		cards.pop();

		ans += bindTwoBundles;
		cards.push(bindTwoBundles);
	}
	
	cout << ans << "\n";
	return 0;
}