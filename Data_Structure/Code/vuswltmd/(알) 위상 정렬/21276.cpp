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
using namespace std;

int n;
vector<int> graph[1001], childName[1001];

map<string, int> NameToIdx;
map<int, string> IdxToName;

int ind[1001];

vector<string> ancestor;

void func(string a)
{
	queue<int> q;
	q.push(NameToIdx[a]);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		for (auto next : graph[cur])
		{
			ind[next]--;

			if (ind[next] == 0)
			{
				childName[cur].push_back(next);
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;

		NameToIdx[name] = i;
		IdxToName[i] = name;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		string a, b;
		cin >> a >> b;

		ind[NameToIdx[a]]++;
		graph[NameToIdx[b]].push_back(NameToIdx[a]);
	}


	for (int i = 0; i < n; i++)
	{
		if (ind[i] == 0)
		{
			ancestor.push_back(IdxToName[i]);
		}
	}

	sort(ancestor.begin(), ancestor.end());

	cout << ancestor.size() << '\n';

	for (auto a : ancestor)
	{
		cout << a << ' ';
	}
	cout << '\n';

	for (auto a : ancestor)
	{
		func(a);
	}

	for (auto a : NameToIdx)
	{
		cout << a.first << ' ' << childName[a.second].size() << ' ';
		vector<string> v;

		for (auto next : childName[a.second])
		{
			v.push_back(IdxToName[next]);
		}

		sort(v.begin(), v.end());
		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << '\n';
	}
}