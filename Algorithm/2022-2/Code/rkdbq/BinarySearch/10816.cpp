#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, card;
vector<int> cardN, cardM;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; i++) {
		cin >> card;
		cardN.push_back(card);
	}
	sort(cardN.begin(), cardN.end());
	cin >> m;
	for (int i{}; i < m; i++) {
		cin >> card;
		auto range{ equal_range(cardN.begin(), cardN.end(), card) };
		cardM.push_back(range.second - range.first);
	}
	for (int i{}; i < m; i++) {
		cout << cardM[i] << " ";
	}

	return 0;
}