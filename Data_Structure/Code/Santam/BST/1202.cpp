#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main()
{
	multiset<int> b;
	vector<pair<int, int>> jew;
	int n, k;
	long long res = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int m, v;
		cin >> m >> v;
		jew.push_back(make_pair(v, m));
	}
	sort(jew.begin(), jew.end(),greater<>());
	for (int j = 0;j < k;j++)
	{
		int temp;
		cin >> temp;
		b.insert(temp);
	}
	for (auto cnt = jew.begin();cnt != jew.end();cnt++)
	{
		if (b.empty()) break;
		auto at = b.lower_bound(cnt->second);
		if (at == b.end()) continue;
		else b.erase(at);
		res += cnt->first;
	}
	cout << res;
	return 0;
}
/*
보석의 가치가 높은 순으로 정렬하고 순서대로 가방에 맞는지 넣어 확인한다. 맞으면 그 가방은 제거한다
1. 보석의 정보를 저장할 벡터와 가방의 정보를 저장할 multiset을 만든다.
2. 보석의 정보가 두가지 이므로  pair활용해 저장, 가방의 정보는 넣기만 하면 자동 정렬되므로 그냥 넣어준다.
==> 여기서 보석의 정보를 multimap에 안넣는 이유는 넣어줄때마다 생기는 시간복잡도가 너무 크기 때문에 o(1)인 vector이용
3. 2번까지 한 후에는 가장 가치가 높은 보석부터 내림차순으로 가방이 견딜수 있는 무게랑 비교해 맞으면 그 가방을 multiset에서 erase해준다.
*/