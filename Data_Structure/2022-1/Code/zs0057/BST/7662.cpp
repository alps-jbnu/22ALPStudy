#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int q;
		cin >> q;
		multiset<int> ms;
		while (q--) {
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I') {
				ms.insert(n);
			}
			else {
				if (ms.empty()) continue;
				else if (n == 1) ms.erase(prev(ms.end()));
				else ms.erase(ms.begin());
			}
		}
		if (ms.empty()) { 
			cout << "EMPTY" << '\n';
		}
		else {
			cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
		}
	}
}