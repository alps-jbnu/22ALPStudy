#include <bits/stdc++.h>
const int MAX = 10000 + 1;
using namespace std;

struct Edge
{
	int x, y, c;
	bool operator<(const Edge& e)
	{
		return c < e.c;
	}
};

int N, M, T, idx = 0;
int parent[MAX];
long long int result = 0;
vector<Edge> vec;

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	int a = Find(x), b = Find(y);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> T;
	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;

		vec.push_back({ a, b, c });
	}
	sort(vec.begin(), vec.end());

	for (int i = 1; i <= N; i++) parent[i] = i;

	for (Edge it : vec)
	{
		if (Find(it.x) != Find(it.y))
		{
			Union(it.x, it.y);
			result += (it.c + (T * idx++));
		}
	}

	cout << result;

	return 0;
}