#include <bits/stdc++.h>
using namespace std;

int N, P, L, M;
set<int> level[101];
int number[100001];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		number[P] = L;
		level[L].insert(P);
	}

	cin >> M;
	while (M--) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			cin >> P >> L;
			number[P] = L;
			level[L].insert(P);
		}
		else if (cmd == "recommend") {
			int x;
			cin >> x;
			if (x == 1) {
				for (int i = 100; i >= 0; i--) {
					if (level[i].empty()) continue;
					cout << *prev(level[i].end()) << '\n';
					break;
				}
			}
			else {
				for (int i = 0; i < 101; i++) {
					if (level[i].empty()) continue;
					cout << *(level[i].begin()) << '\n';
					break;
				}
			}
		}
		else {
			int p;
			cin >> p;
			level[number[p]].erase(p);
		}
	}
}