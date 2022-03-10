#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int cnt[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	string stringN = to_string(N);
	for (int i{}; i < stringN.size(); i++) {
		if (stringN[i] == '6' || stringN[i] == '9') {
			if (cnt[6] > cnt[9]) cnt[9]++;
			else cnt[6]++;
		}
		else {
			cnt[stringN[i] - '0']++;
		}
	}
	cout << *max_element(cnt, cnt+10);

	return 0;
} 