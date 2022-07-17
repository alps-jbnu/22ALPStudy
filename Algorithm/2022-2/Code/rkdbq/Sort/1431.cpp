#include <iostream>
#include <algorithm>
using namespace std;

int N;
string guitar[51];

bool cmp(string &a, string &b) {
	if (a.length() != b.length()) return a.length() < b.length();
	else {
		int sumA{}, sumB{};
		for (int i{}; i < a.length(); i++) if (a[i] >= '0' && a[i] <= '9') sumA += a[i] - '0';
		for (int i{}; i < b.length(); i++) if (b[i] >= '0' && b[i] <= '9') sumB += b[i] - '0';
		if (sumA != sumB) return sumA < sumB;
		else return a < b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) cin >> guitar[i];
	sort(guitar, guitar + N, cmp);
	for (int i{}; i < N; i++) cout << guitar[i] << "\n";
	return 0;
}