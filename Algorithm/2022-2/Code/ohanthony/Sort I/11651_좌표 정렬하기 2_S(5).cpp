#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, x, y;
vector<pair<int, int>> v;

bool compare(pair<int, int> v1, pair<int, int> v2) {
	if (v1.Y == v2.Y) return v1.X < v2.X;
	else return v1.Y < v2.Y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end(), compare);
	
	for (auto i : v) {
		cout << i.X << " " << i.Y << "\n";
	}

	return 0;
}