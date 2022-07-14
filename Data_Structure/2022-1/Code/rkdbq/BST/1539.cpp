#define first node
#define second depth

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, P[250001];
long long ans{ 1 };
set<pair<int, int>> tree;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cin >> P[0];
	tree.insert({ P[0], 1 });
	for (int i{ 1 }; i < N; i++) {
		cin >> P[i];
		int lowerDepth{}, upperDepth{};
		if(tree.lower_bound({ P[i], 0 }) != tree.begin()) lowerDepth = (*--tree.lower_bound({P[i], 0})).depth;
		if(tree.upper_bound({ P[i], 0 }) != tree.end()) upperDepth = (*tree.upper_bound({P[i], 0})).depth;
		int iDepth{ max(lowerDepth, upperDepth) + 1 };
		tree.insert({ P[i], iDepth });
		ans += iDepth;
	}
	cout << ans;
	return 0;
}