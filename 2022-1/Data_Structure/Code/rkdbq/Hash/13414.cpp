#include <iostream>
#include <unordered_map>
using namespace std;

int K, L;
string stu;
unordered_map<string, int> stuMap;
string ans[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K >> L;
	for (int i{}; i < L; i++) {
		cin >> stu;
		stuMap[stu] = i;
		ans[i] = stu;
	}

	int cnt{};
	for (int i{}; i < L; i++) {
		if (cnt == K) break;
		if (stuMap[ans[i]] == i) {
			cout << ans[i] << "\n";
			cnt++;
		}
	}

	return 0;
}