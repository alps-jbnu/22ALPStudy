#include <iostream>
#include <set>
using namespace std;

multiset<int> ms;
int T, k;
char op;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i{}; i < T; i++) {
		ms.clear();
		cin >> k;
		for (int j{}; j < k; j++) {
			cin >> op;
			int n{};
			if (op == 'I') {
				cin >> n;
				ms.insert(n);
			}
			else if (op == 'D') {
				cin >> n;
				if (ms.empty()) continue;
				if (n == -1) ms.erase(ms.begin());
				else if (n == 1) ms.erase(--ms.end());
			}
		}
		if (ms.empty()) cout << "EMPTY\n";
		else cout << *(--ms.end()) << " " << *ms.begin() << "\n";
	}
	return 0;
}	