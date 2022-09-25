#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, p, l, x;
multiset<pair<int, int>> level;
map<int, int> num;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	while (n--) {
		cin >> p >> l;
		num[p] = l;
		level.insert({ l, p });
	}

	cin >> m;
	while (m--) {
		string order;
		cin >> order;

		if (order == "recommend") {
			cin >> x;

			if (x == 1) cout << prev(level.end())->Y << "\n";
			else cout << level.begin()->Y << "\n";
		} 
		else if (order == "add") {
			cin >> p >> l;
			num[p] = l;
			level.insert({ l, p });
		}
		else if (order == "solved") {
			cin >> p;
			level.erase({ num[p], p });
			num.erase(p);
			
		}
	}
	return 0;
}