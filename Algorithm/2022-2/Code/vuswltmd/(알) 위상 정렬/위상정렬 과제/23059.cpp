#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

int N; int item_count = 0;
unordered_map<string, int> NameToIdx;
unordered_map<int, string> IdxToName;
int ind[400001];
vector<int> graph[400001], result[400001];


bool cmp(int a, int b) {
	return IdxToName[a] < IdxToName[b];
}

void solve()
{
	queue<pair<int, int>> q;

	for (int i = 0; i < item_count; i++)
	{
		if (ind[i] == 0)
		{
			q.push({ i, 0 });
			result[0].push_back(i);

			// 각 단계별로 i 를 넣고 알파벳순으로 정렬
		}
	}

	while (item_count--)
	{
		if (q.empty())
		{
			cout << "-1\n";
			return ;
		}

		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (auto next : graph[cur])
		{
			ind[next]--;
			if (ind[next] == 0)
			{
				q.push({ next, cnt + 1 });
				result[cnt + 1].push_back(next);
			}
		}
	}

	for (int i = 0; ; i++)
	{
		if (!result[i].size()) return;

		sort(result[i].begin(), result[i].end(), cmp);

		for (int j = 0; j < result[i].size(); j++)
		{
			cout << IdxToName[result[i][j]] << "\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string a, b;
		cin >> a >> b;

		if (NameToIdx.find(a) == NameToIdx.end())
		{
			NameToIdx.insert({ a, item_count });
			IdxToName.insert({ item_count++, a });
		}

		if (NameToIdx.find(b) == NameToIdx.end())
		{
			NameToIdx.insert({ b, item_count });
			IdxToName.insert({ item_count++, b });
		}

		ind[NameToIdx[b]]++;
		graph[NameToIdx[a]].push_back(NameToIdx[b]);
	}

	solve();
}



