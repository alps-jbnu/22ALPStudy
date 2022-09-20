#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		multiset<int> Q;
		int k;
		cin >> k;
		while (k--) {
			string word;
			cin >> word;

			if (word == "I") { // I인 경우 값 삽입
				int num;
				cin >> num;
				Q.insert(num);
			}
			else if (word == "D") { // D인 경우 1 => 최댓값 삭제, -1 => 최솟값 삭제
				int num;
				cin >> num;

				if (!Q.empty()) { // Q가 비어있지 않는 경우에만 작동
					if (num == 1) Q.erase(prev(Q.end()));
					else Q.erase(Q.begin());
				}
			}
		}
		if (Q.empty()) cout << "EMPTY\n";
		else cout << *prev(Q.end()) << ' ' << *Q.begin() << "\n";
	}
	return 0;
}