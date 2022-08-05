#include <iostream>
#include <algorithm>
using namespace std;

int N;
int rope[100001];
int k, w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) cin >> rope[i];
	sort(rope, rope + N, greater<>());
	for (int i{}; i < N; i++) w = max(w, rope[i] * (++k));
	cout << w << "\n";
	return 0;
}