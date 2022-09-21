#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

multiset<pair<int, int>> ms; // 따로 정렬할 필요 없이 자동적으로 오름차순으로 정렬

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		// 끝시간 기준으로 정렬해야 고려사항 적어짐
		ms.insert({ end, start });
	}

	int count = 0;
	auto itsStart = ms.begin();
	for (auto its = ms.begin(); its != ms.end(); its++) {
		if (its == ms.begin()) continue;
		if (itsStart->X <= its->Y) {
			itsStart = its;
			count++;
		}
	}
	cout << count + 1;
	return 0;
}
