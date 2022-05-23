#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1000 + 1;

int N, M;
int Visited[MAX];
int arr[MAX];
vector<pair<int, int>> vec[MAX];

int BFS(int x, int y)
{
	queue<int> q;
	q.push(x);
	arr[x] = 0;

	while (!q.empty())
	{
		int next = q.front();
		q.pop();

		for (auto cnt : vec[next])
		{
			if (arr[cnt.first] >= 0) continue;

			arr[cnt.first] = arr[next] + cnt.second;
			q.push(cnt.first);
		}
	}
	return arr[y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N - 1; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;

		vec[x].push_back({ y, d });
		vec[y].push_back({ x, d });
	}
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		memset(arr, -1, sizeof(arr));

		cout << BFS(x, y) << "\n";
	}

	return 0;
}