#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, K;
pair<int, int> VM[300001];
multiset<int> C;
long long ans;

void steal() {
	for (int i{ N - 1 }; i >= 0; i--) {
		multiset<int>::iterator curCiter{ C.lower_bound(VM[i].second) };
		if (curCiter == C.end()) continue;
		C.erase(curCiter);
		ans += VM[i].first;
	}
	cout << ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	for (int i{}; i < N; i++) {
		int m, v;
		cin >> m >> v;
		VM[i] = { v, m };
	}
	sort(VM, VM + N);
	for (int i{}; i < K; i++) {
		int c;
		cin >> c;
		C.insert(c);
	}
	steal();
	return 0;
}