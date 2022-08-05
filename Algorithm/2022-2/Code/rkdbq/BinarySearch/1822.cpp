#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num;
vector<int> A, B;
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i{}; i < n; i++) {
		cin >> num;
		A.push_back(num);
	}
	for (int i{}; i < m; i++) {
		cin >> num;
		B.push_back(num);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (auto i{ A.begin() }; i != A.end(); i++) {
		if (!binary_search(B.begin(), B.end(), *i)) ans.push_back(*i);
	}
	cout << ans.size() << "\n";
	for (int i{}; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}