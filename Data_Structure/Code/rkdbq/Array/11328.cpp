#include <iostream>
using namespace std;

int N; // Testcase
string s1, s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		int cnt1[27]{}, cnt2[27]{};
		int ans{};
		cin >> s1 >> s2;
		for (int j{}; j < s1.size(); j++) {
			cnt1[s1[j] - 'a']++;
		}
		for (int j{}; j < s2.size(); j++) {
			cnt2[s2[j] - 'a']++;
		}
		for (int j{}; j < 27; j++) {
			if (cnt1[j] == cnt2[j]) ans++;
		}
		if (ans == 27) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
	}

	return 0;
}