#include<bits/stdc++.h>
using namespace std;
multiset <int> pro[102];
int prolev[100002];

int main() {
	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int p, l;
		cin >> p >> l;
		prolev[p] = l;
		pro[l].insert(p);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (s == "add") {
			int a, b;
			cin >> a >> b;
			prolev[a] = b;
			pro[b].insert(a);
		}
		else if (s == "recommend") {
			int a;
			cin >> a;
			
			if (a == 1) {
				for (int i = 100; i >= 0; i--) {
					if (pro[i].empty())	continue;
					cout << *(prev(pro[i].end())) << '\n';
					break;
				}
			}
			else if (a == -1) {
				for (int i = 1; i< 101; i++) {
					if (pro[i].empty())	continue;
					cout << *(pro[i].begin()) << '\n';
					break;
				}
			}
		}
		else if (s == "solved") {
			int a;
			cin >> a;
			pro[prolev[a]].erase(a);
		}

	}
}