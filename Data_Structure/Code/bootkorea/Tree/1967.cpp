#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 10000 + 1
using namespace std;

int N, point, length = 0;
bool Visited[MAX] = { 0, };
vector<pair<int, int>> vec[MAX];

void DFS(int pt, int len)
{
	if (Visited[pt] == true) return;

	Visited[pt] = true;

	if (length < len)
	{
		length = len;
		point = pt;
	}

	for (int i = 0; i < vec[pt].size(); i++)
	{
		DFS(vec[pt][i].first, len + vec[pt][i].second);
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b, c });
		vec[b].push_back({ a, c });
	}

	DFS(1, 0);

	length = 0;
	memset(Visited, false, sizeof(Visited));

	DFS(point, 0);
	cout << length;

	return 0;
}