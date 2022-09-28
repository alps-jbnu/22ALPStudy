#include <bits/stdc++.h>
#define MAX 1000 + 1
using namespace std;

int N, M;
int indegree[MAX];
vector<int> ancester;
vector<string> vec;
vector<vector<int>> family(MAX), child(MAX);
map<string, int> idx;

void Solve()
{
	queue<int> q;

	for (int i = 0; i < N; i++)
	{
		if (!indegree[i])
		{
			ancester.push_back(i);
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		for (int next : family[temp])
		{
			indegree[next]--;

			if (!indegree[next])
			{
				child[temp].push_back(next);
				q.push(next);
			}
		}
	}
	cout << ancester.size() << "\n";

	for (int it : ancester) cout << vec[it] << " ";
	cout << "\n";

	for (int i = 0; i < N; i++)
	{
		cout << vec[i] << " " << child[i].size() << " ";

		sort(child[i].begin(), child[i].end());

		for (int it : child[i]) cout << vec[it] << " ";
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str; cin >> str;
		vec.push_back(str);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		idx[vec[i]] = i;
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string s1, s2; cin >> s1 >> s2;

		family[idx[s2]].push_back(idx[s1]);
		indegree[idx[s1]]++;
	}

	Solve();

	return 0;
}