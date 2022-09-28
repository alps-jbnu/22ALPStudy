#include <bits/stdc++.h>
#include <unordered_map>
#define pii pair<int, int>
const int MAX = 400000 + 1;
using namespace std;

int N, idx = 0;
int indegree[MAX];
vector<int> vec[MAX], result[MAX];
unordered_map<int, string> imap;
unordered_map<string, int> smap;

bool Compare(int a, int b) { return imap[a] < imap[b]; }

void Solve()
{
	queue<pii> q;
	for (int i = 0; i < idx; i++)
	{
		if (!indegree[i])
		{
			q.push({ i, 0 });
			result[0].push_back(i);
		}
	}
	while (idx--)
	{
		if (q.empty())
		{
			cout << "-1\n";
			return;
		}

		int a = q.front().first, cnt = q.front().second;
		q.pop();

		for (int next : vec[a])
		{
			indegree[next]--;
			if (!indegree[next])
			{
				q.push({ next, cnt + 1 });
				result[cnt + 1].push_back(next);
			}
		}
	}

	for (int i = 0; ; i++)
	{
		if (!result[i].size()) return;

		sort(result[i].begin(), result[i].end(), Compare);

		for (int j = 0; j < result[i].size(); j++)
		{
			cout << imap[result[i][j]] << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;

		if (smap.find(s1) == smap.end())
		{
			smap.insert({ s1, idx });
			imap.insert({ idx++, s1 });
		}

		if (smap.find(s2) == smap.end())
		{
			smap.insert({ s2, idx });
			imap.insert({ idx++, s2 });
		}

		int x = smap[s1], y = smap[s2];
		vec[x].push_back(y);
		indegree[y]++;
	}

	Solve();

	return 0;
}