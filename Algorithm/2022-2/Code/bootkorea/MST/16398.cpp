#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
const int MAX = 1000 + 1;
using namespace std;

int N;
ll result = 0;
int parent[MAX];
int Flow[MAX][MAX];
vector<pair<int, pii>> vec;

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Merge(int x, int y)
{
	int a = Find(x), b = Find(y);

	if (a == b) return;

	parent[a] = b;
}

bool Group(int x, int y)
{
	int a = Find(x), b = Find(y);

	if (a == b) return 1;
	else return 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Flow[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			vec.push_back({ Flow[i][j], { i, j } });
		}
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		if (!Group(vec[i].second.first, vec[i].second.second))
		{
			result += vec[i].first;
			Merge(vec[i].second.first, vec[i].second.second);
		}
	}

	cout << result;

	return 0;
}