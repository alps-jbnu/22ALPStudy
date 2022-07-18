#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
pair<int, int> lines[1000001];
vector<pair<int, int>> sumLines;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; i++) {
		cin >> lines[i].first >> lines[i].second;
	}
	sort(lines, lines + n);

	int x{ lines[0].first }, y{ lines[0].second };
	for (int i{}; i < n; i++) {
		if (y >= lines[i].first) {
			if(y < lines[i].second) y = lines[i].second;
		}
		else {
			sumLines.push_back({ x,y });
			x = lines[i].first;
			y = lines[i].second;
		}
	}
	sumLines.push_back({ x,y });
	for (int i{}; i < sumLines.size(); i++) {
		ans += sumLines[i].second - sumLines[i].first;
	}
	cout << ans << "\n";

	return 0;
}