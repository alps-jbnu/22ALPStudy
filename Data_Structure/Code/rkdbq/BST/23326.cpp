#include <iostream>
#include <set>
using namespace std;

int N, Q, cur{ 1 };
set<int> hotPlace;

void query1(int i) {
	if (hotPlace.find(i) == hotPlace.end()) hotPlace.insert(i);
	else hotPlace.erase(i);
}
void query2(int x) {
	cur += x;
	cur %= N;
	if (cur == 0) cur = N;
}
int query3() {
	if (hotPlace.empty()) return -1;
	auto lowerBoundIsEnd{ *hotPlace.lower_bound(0) };
	auto lowerBoundIsNotEnd{ *hotPlace.lower_bound(cur) };
	if (hotPlace.lower_bound(cur) == hotPlace.end()) return (N - cur) + lowerBoundIsEnd;
	else return lowerBoundIsNotEnd - cur;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> Q;
	for (int i{ 1 }; i <= N; i++) {
		bool isPlaceHot;
		cin >> isPlaceHot;
		if (isPlaceHot) hotPlace.insert(i);
	}
	for (int i{}; i < Q; i++) {
		int q;
		cin >> q;
		if (q == 1) {
			int i;
			cin >> i;
			query1(i);
		}
		else if (q == 2) {
			int x;
			cin >> x;
			query2(x);
		}
		else if (q == 3) {
			cout << query3() << "\n";
		}
	}

	return 0;
}