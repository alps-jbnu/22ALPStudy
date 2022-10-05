#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<pair<int, int>> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i].first >> vec[i].second;
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}

	return 0;
}