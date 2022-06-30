#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, h, k;
vector<pair<int, int>> stu;
multiset<int> ms;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		cin >> h >> k;
		stu.push_back({ h,k });
	}
	sort(stu.begin(), stu.end(), greater<pair<int, int>>());
	for (int i{}; i < N; i++) {
		int curK{ stu[i].second };
		
		if (ms.empty()) ms.insert(1);
		else {
			auto lb{ ms.lower_bound(curK) };

			if (lb == ms.begin()) ms.insert(1);
			else {
				lb = --ms.lower_bound(curK);
				ms.insert(*lb + 1);
				ms.erase(lb);
			}
		}	
	}
	cout << ms.size() << "\n";

	return 0;
}