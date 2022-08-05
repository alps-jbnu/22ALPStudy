#define first level
#define second problem

#include <iostream>
#include <set>
using namespace std;

int N, P, L, G, M;
int levelOf[100001];
set<pair<int, int>> groupOf[101];
set<pair<int, int>> all;

void recommend(int g, int x) {
	if (x == 1) cout << (*--groupOf[g].end()).problem << "\n";
	else if (x == -1) cout << (*groupOf[g].begin()).problem << "\n";
}
void recommend2(int x) {
	if (x == 1) cout << (*--all.end()).problem << "\n";
	else if (x == -1) cout << (*all.begin()).problem << "\n";
}
int recommend3(int x, int l) {
	auto lowerBound{ all.lower_bound({ l, 0 }) };
	if (x == 1 && lowerBound != all.end()) return (*lowerBound).problem;
	else if (x == -1 && lowerBound != all.begin()) return (*--lowerBound).problem;
	else return -1;
}
void add(int p, int l, int g) {
	levelOf[p] = l;
	groupOf[g].insert({ l, p });
	all.insert({ l, p });
}
void solved(int p) {
	for (int i{ 1 }; i < 101; i++) {
		groupOf[i].erase({ levelOf[p], p });
	}
	all.erase({ levelOf[p], p });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		cin >> P >> L >> G;
		levelOf[P] = L;
		groupOf[G].insert({ L, P });
		all.insert({ L, P });
	}

	cin >> M;
	for (int i{}; i < M; i++) {
		int x, p, l, g;
		string com;
		cin >> com;

		if (com == "recommend") {
			cin >> g >> x;
			recommend(g, x);
		}
		else if (com == "recommend2") {
			cin >> x;
			recommend2(x);
		}
		else if (com == "recommend3") {
			cin >> x >> l;
			cout << recommend3(x, l) << "\n";
		}
		else if (com == "add") {
			cin >> p >> l >> g;
			add(p, l, g);
		}
		else if (com == "solved") {
			cin >> p;
			solved(p);
		}
	}

	return 0;
}