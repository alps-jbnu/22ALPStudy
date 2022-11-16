#include <bits/stdc++.h>
#define MAX 100000 + 1
using namespace std;

int N, M, result = 0;
int Parent[MAX];
vector<pair<int, pair<int, int>>> vec;
vector<int> v;

int Find(int n)
{
	if (n == Parent[n]) return n;
	else return Parent[n] = Find(Parent[n]);
}

bool SameRoot(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y) return true;
	else return false;
}

void Group(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y) return;

	Parent[y] = x;
	N--;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vec.push_back({ c, { a, b } });
	}
	sort(vec.begin(), vec.end());

	for (int i = 1; i <= N; i++)
	{
		Parent[i] = i;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (SameRoot(vec[i].second.first, vec[i].second.second) == false)
		{
			Group(vec[i].second.first, vec[i].second.second);
			v.push_back(vec[i].first);
		}
	}

	for (int i = 0; i < v.size() - 1; i++)
	{
		result += v[i];
	}
	cout << result;

	return 0;
}