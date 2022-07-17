#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> u;
vector<int> two;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int num;
	for (int i{}; i < n; i++) {
		cin >> num;
		u.push_back(num);
	}
	for (int i{}; i < n; i++) {
		for (int j{ i }; j < n; j++) {
			two.push_back(u[i] + u[j]);
		}
	}
	sort(two.begin(), two.end());
	sort(u.begin(), u.end());
	for (int i{ (int)u.size() - 1 }; i >= 0; i--) {
		for (int j{}; j < i; j++) {
			if (binary_search(two.begin(), two.end(), u[i] - u[j])) { cout << u[i] << "\n"; return 0; }
		}
	}
	return 0;
}