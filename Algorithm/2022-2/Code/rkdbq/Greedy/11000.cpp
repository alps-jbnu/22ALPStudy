#define S first
#define T second

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N;
pair<int, int> cls[2000001];
multiset<int> s;

bool cmp(pair<int, int>a, pair<int, int> b) {
	return a.T < b.T;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) cin >> cls[i].S >> cls[i].T;
	sort(cls, cls + N, cmp);
	//for (int i{}; i < N; i++) cout << cls[i].S << " " << cls[i].T << "\n";
	for (int i{ 0 }; i < N; i++) {
		if (!s.empty()) {
			if (s.upper_bound(cls[i].S) != s.begin()) {
				if (*--s.upper_bound(cls[i].S) <= cls[i].S) s.erase(--s.upper_bound(cls[i].S));
			}
		}
		s.insert(cls[i].T);
	}
	cout << s.size() << "\n";

	return 0;
}