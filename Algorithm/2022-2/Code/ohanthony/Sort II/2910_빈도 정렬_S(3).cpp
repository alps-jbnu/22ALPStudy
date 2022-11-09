#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> v; // first: 입력값, second: 입력값 빈도수

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.Y > b.Y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		bool already = false;
		int num;
		cin >> num;

		for (auto &i : v) {
			if (i.X == num) {
				already = true;
				i.Y++;
				break;
			}
		}
		if (already == false) v.push_back({ num, 1 });
	}

	stable_sort(v.begin(), v.end(), compare);
	for (auto nxt : v) {
		while (nxt.Y--) cout << nxt.X << " ";
	}

	return 0;
}
