#include <bits/stdc++.h>
const int MAX = 1000 + 1;
using namespace std;

struct Edge
{
	int x, y, d;
	bool operator<(const Edge& e)
	{
		return d < e.d;
	}
};

int N, M, result = 0;
int parent[MAX];
char arr[MAX];
bool flag = 0;
vector<Edge> edge;

bool Comp(tuple<int, int, int>& t1, tuple<int, int, int>& t2)
{
	int a, b, c, x, y, z;
	tie(a, b, c) = t1;
	tie(x, y, z) = t2;

	if (a == x && b == y && c > z) cout << 1;
	else return 0;
}

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	int a = Find(x), b = Find(y);
	parent[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;

		if (arr[u] != arr[v]) edge.push_back({ u, v, d });
	}
	sort(edge.begin(), edge.end());

	for (auto& it : edge)
	{

		if (Find(it.x) != Find(it.y))
		{
			Union(it.x, it.y);
			result += it.d;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (Find(1) != Find(i)) flag = 1;
	}

	cout << (flag ? -1 : result);

	return 0;
}