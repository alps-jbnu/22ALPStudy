#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 400000 + 1;
using namespace std;

int N, idx = 0;
int arr[MAX];
vector<int> vec[MAX], result[MAX];
map<int, string> imap;
map<string, int> smap;

bool compare(int a, int b) { return imap[a] < imap[b]; }

void Solve()
{
	queue<pii> q;
	for (int i = 0; i < idx; i++)
	{
		if (!arr[i])
		{
			q.push({ i, 0 });
			vec[0].push_back(i);
		}
	}

	for (int i = 0; i < idx; i++)
	{
		if (q.empty())
		{
			cout << "-1\n";
			return;
		}

		int a = q.front().first, b = q.front().second;
		q.pop();

		for (int next : vec[a])
		{
			arr[next]--;
			if (!arr[next])
			{
				q.push({ next, b + 1 });
				result[b + 1].push_back(next);
			}
		}
	}
	
	for (int i = 0; ; i++)
	{
		if (!result[i].size()) return;

		sort(result[i].begin(), result[i].end(), compare);

		for (int j = 0; j < result[i].size(); i++)
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
		arr[y]++;
	}
	
	Solve();

	return 0;
}