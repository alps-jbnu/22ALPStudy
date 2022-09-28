#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long

multiset<pair<int, int> > jewel;
multiset<int> bag;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k; // n: 총 보석의 개수, k: 가방의 개수

	for(int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v; // m: 보석의 무게, v: 보석 가격
		jewel.insert({ v, m }); // 보석 가격을 오름차순으로 정렬
	}

	while (k--) {
		int c;
		cin >> c; // c: 가방에 담을 수 있는 최대 무게
		bag.insert(c);
	}

	ll result = 0;
	auto its = jewel.end();  
	its--; // jewel의 보석 가격 중 가장 큰 값을 가리킨다.

	for (int i = 0; i < n; i++) {
		if (bag.lower_bound(its->Y) == bag.end()) {
			its--;
			continue;
		}

		result += its->X;

		bag.erase(bag.lower_bound((its->Y)));
		its--;
	}

	cout << result;
	return 0;
} 