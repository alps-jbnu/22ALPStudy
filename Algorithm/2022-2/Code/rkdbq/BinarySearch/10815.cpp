#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, card;
vector<int> cards;
vector<bool> have;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; i++) {
		cin >> card;
		cards.push_back(card);
	}
	sort(cards.begin(), cards.end());

	cin >> m;
	for (int i{}; i < m; i++) {
		cin >> card;
		have.push_back(binary_search(cards.begin(), cards.end(), card));
	}
	for (int i{}; i < m; i++) {
		cout << have[i] << " ";
	}
	return 0;
}