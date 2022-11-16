#include<bits/stdc++.h>
using namespace std;

vector<string> v;

bool compare(const string a, const string b) {
	// 1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
	if (a.length() != b.length()) return a.length() < b.length();
	else {
		int count_a = 0;
		int count_b = 0;

		for (int i = 0; i < a.length(); i++) if ('A' - a[i] > 0) count_a += a[i] - '0';
		for (int i = 0; i < b.length(); i++) if ('A' - b[i] > 0) count_b += b[i] - '0';

		if (count_a != count_b) return count_a < count_b;
		else return a < b; //  사전 순
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string siral;
		cin >> siral;
		v.push_back(siral);
	}

	sort(v.begin(), v.end(), compare);
	for (auto nxt : v) cout << nxt << "\n";
	return 0;
}
