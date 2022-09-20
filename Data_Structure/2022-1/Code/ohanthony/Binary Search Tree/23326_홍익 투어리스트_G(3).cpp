#include<bits/stdc++.h>
using namespace std;

int n, q, Q, y, x, A;
set<int> section; // 명소들의 위치만 고려

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> q; // n: 구역의 개수, q: 쿼리의 개수
	for (int i = 1; i <= n; i++) {
		cin >> A;
		if (A == 1) section.insert(i); // 1인 경우에만 명소로 처리함
	}

	int position = 1; // position: 도현의 위치
	while (q--) {
		cin >> Q;

		if (Q == 1) {
			cin >> y;
			if (section.find(y) != section.end()) section.erase(y);
			else section.insert(y);
		}
		else if (Q == 2) {
			cin >> x;
			position = (position + x - 1) % n + 1;
		}
		else if (Q == 3) {
			if (section.empty()) cout << -1 << "\n";
			else {
				//auto its = section.lower_bound(position);
				set<int>::iterator its = section.lower_bound(position);
				if (its != section.end()) cout << *its - position << "\n"; // 자기 지점부터 끝 지점 전에 명소가 있을 경우 
				else cout << n - position + *section.begin() << "\n";	   // 자기 지점부터 끝 지점 까지 명소가 없는 경우 시계방향으로 한바퀴 돈다.
			}
		}
	}

	return 0;
}