#include <iostream>
#include <algorithm>
using namespace std;

int N;
int pos[1000001];
int neg[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		int k;
		cin >> k;
		if (k < 0) neg[-k]++;
		else pos[k]++;
	}
	for (int i{ 1000000 }; i > 0; i--) { if (neg[i] != 0) for (int j{}; j < neg[i]; j++) cout << -i << "\n"; }
	for (int i{}; i < 1000001; i++) { if (pos[i] != 0) for (int j{}; j < pos[i]; j++) cout << i << "\n"; }
	return 0;
}