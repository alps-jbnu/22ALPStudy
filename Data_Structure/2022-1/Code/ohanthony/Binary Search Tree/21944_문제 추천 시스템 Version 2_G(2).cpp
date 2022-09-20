#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define INF 987654321

int N, M, P, L, G, x;
string order;

map<int, multiset<pair<int, int>> > algo_lev_n; // key: 알고리즘 분류, value: 난이도, 문제번호
map<int, pair<int, int>> num_lev_algo; // key: 문제번호, value: 난이도, 알고리즘 분류
multiset<pair<int, int>> level;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	while (N--) {
		cin >> P >> L >> G;
		num_lev_algo[P] = { L, G };
		algo_lev_n[G].insert({ L, P });
		level.insert({ L, P });
	}

	cin >> M;

	while (M--) {
		cin >> order;

		if (order == "recommend") {
			cin >> G >> x;

			// x=1, 알고리즘 분류가 g인 문제 중 가장 어려운 문제 번호를 출력
			if (x == 1) cout << prev(algo_lev_n[G].end())->Y << "\n";
			else cout << algo_lev_n[G].begin()->Y << "\n";
		}
		else if (order == "recommend2") {
			cin >> x;

			// x=1, 알고리즘 분류와 상관없이 가장 어려운 문제 번호를 출력
			if (x == 1) cout << prev(level.end())->Y << "\n";
			else cout << level.begin()->Y << "\n";
		}
		else if (order == "recommend3") {
			cin >> x >> L;

			// x=1, 난이도 L보다 크거나 같은 문제 중 가장 쉬운 문제 번호 출력
			if (x == 1) {
				auto its = level.lower_bound({ L, -INF });
				if (its != level.end()) cout << its->Y << "\n";
				else cout << -1 << "\n";
			}
			else {
				auto its = level.upper_bound({ L, -INF });
				if (its != level.begin()) cout << (--its)->Y << "\n";
				else cout << -1 << "\n";
			}
		}
		else if (order == "add") {
			cin >> P >> L >> G;
			num_lev_algo[P] = { L, G };
			algo_lev_n[G].insert({ L, P });
			level.insert({ L, P });
		}
		else if (order == "solved") {
			cin >> P;
			algo_lev_n[num_lev_algo[P].Y].erase({ num_lev_algo[P].X, P});
			level.erase({ num_lev_algo[P].X, P });
			num_lev_algo.erase(P);
		}
	}
	return 0;
}