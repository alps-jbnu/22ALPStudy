#include<bits/stdc++.h>
using namespace std;
pair<int, int> ma[300002];
multiset<int> bag;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		int weight, price;
		cin >> weight >> price;
		ma[i]={ price, weight };
	}
	sort(ma, ma + n);

	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		bag.insert(k);
	}

	for (int i = n - 1; i >= 0;i--) {
		auto c = bag.lower_bound( ma[i].second );
		if (c == bag.end())	continue;
		res += ma[i].first;
		bag.erase(c);
	}
	cout << res;
}