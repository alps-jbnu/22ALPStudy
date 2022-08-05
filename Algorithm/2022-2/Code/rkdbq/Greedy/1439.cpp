#include <iostream>
using namespace std;

char bef;
string S;
int cnt[2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	bef = S[0];
	cnt[bef - '0']++;
	for (int i{ 1 }; i < S.length(); i++) {
		if (S[i] != bef) {
			bef = S[i];
			cnt[bef - '0']++;
		}
	}
	cout << min(cnt[0], cnt[1]) <<"\n";

	return 0;
}