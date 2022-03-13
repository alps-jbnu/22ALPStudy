#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char S[101]{};
	int ans[26]{};
	cin >> S;
	int i{};
	while (S[i] != 0) {
		ans[S[i] - 'a']++;
		i++;
	}
	for (int j{}; j < 26; j++) {
		cout << ans[j] << " ";
	}

}