#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, string> > v;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.X < b.X;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int age;
		string name;
		cin >> age >> name;
		v.push_back({ age, name });
	}
	
	// stable_sort: 하나의 요소를 정렬 했을 때 다른 요소들의 정렬 순서도 정렬 전과 같이 그대로 유지 될 수 있도록 하는 정렬
	stable_sort(v.begin(), v.end(), compare);
	for (auto nxt : v) cout << nxt.X << " " << nxt.Y << "\n";
	
	return 0;
}
