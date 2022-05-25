#define first level
#define second problem

#include <iostream>
#include <set>
using namespace std;

int N, P, L, M;
int levelOf[100001];
multiset<pair<int, int>> ms;

void recommend(int n) {
	if (n == 1) cout << (*--ms.end()).problem << "\n";
	else if (n == -1) cout << (*ms.begin()).problem << "\n";
}
void add(int l, int p) {
	ms.insert({ l, p });
}
void solved(int p) {
	ms.erase({ levelOf[p], p });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		cin >> P >> L;
		levelOf[P] = L;
		ms.insert({ L, P });
	}

	cin >> M;
	for (int i{}; i < M; i++) {
		int n, p, l;
		string com;
		cin >> com;
		if (com == "recommend") {
			cin >> n;
			recommend(n);
		}
		else if (com == "add") {
			cin >> p >> l;
			add(l, p);
		}
		else if (com == "solved") {
			cin >> p;
			solved(p);
		}
	}

	return 0;
}