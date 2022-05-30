#include <bits/stdc++.h>
using namespace std;

set<int> level[101];
set<int> algolevel[101][101];
pair<int, int> lg[100001];
int n, p, m, l, g;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> l >> g;
		level[l].insert(p);
		algolevel[g][l].insert(p);
		lg[p] = { l, g };
	}
	cin >> m;
	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "recommend") {
			int g, x;
			cin >> g >> x;
			if (x == 1) {
				for (int i = 100; i >= 0; i--) {
					if (algolevel[g][i].empty()) continue;
					cout << *prev(algolevel[g][i].end()) << '\n';
					break;
				}
			}
			else {
				for (int i = 0; i < 101; i++) {
					if (algolevel[g][i].empty()) continue;
					cout << *algolevel[g][i].begin() << '\n';
					break;
				}
			}
		}
		else if (cmd == "recommend2") {
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
					cout << *level[i].begin() << '\n';
					break;
				}
			}
		}
		else if (cmd == "recommend3") {
			int x, l;
			cin >> x >> l;
			int flag = 0;
			if(x == 1) {
				for (int i = l; i <= 100; i++) {
					if (level[i].empty()) continue;
					cout << *level[i].begin() << '\n';
					flag++;
					break;
				}
				if (flag == 0) {
					cout << -1 << '\n';
				}
			}
			else if (x == -1) {
				for (int i = l-1; i >= 0; i--) {
					if (level[i].empty()) continue;
					cout << *prev(level[i].end()) << '\n';
					flag++;
					break;
				}
				if (flag == 0) {
					cout << -1 << '\n';
				}
			}
			
		}
		else if (cmd == "add") {
			int p, l, g;
			cin >> p >> l >> g;
			level[l].insert(p);
			algolevel[g][l].insert(p);
			lg[p] = { l, g };
		}
		else {
			int p;
			cin >> p;
			int l, g;
			l = lg[p].first;
			g = lg[p].second;
			algolevel[g][l].erase(p);
			level[l].erase(p);
		}
	}
}