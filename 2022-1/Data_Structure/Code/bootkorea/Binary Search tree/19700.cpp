#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
const int MAX = 500000 + 1;
const int INF = 987654321;
typedef pair<int, int> pii;

int N;
vector<int> vec;
priority_queue<pair<int, int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int h, k; cin >> h >> k;
		pq.push({ h, k });
	}

	while (!pq.empty())
	{
		int cnt = pq.top().second;
		pq.pop();

		int idx = upper_bound(vec.begin(), vec.end(), cnt, greater<>()) - vec.begin();

		if (idx == vec.size()) vec.push_back(1);
		else vec[idx]++;
	}
	cout << vec.size();

	return 0;
}