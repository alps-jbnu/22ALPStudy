#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 500 + 1;

int N, M;
int cnt = 0, result;
int Visited[MAX];
vector<int> vec[MAX];

int DFS(int n, int x)
{
	Visited[n] = 1;

	for (int i = 0; i < vec[n].size(); i++)
	{
		if (vec[n][i] == x) continue;
		if (Visited[vec[n][i]]) return 0; // cycle
		if (DFS(vec[n][i], n) == 0) return 0; // no tree
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1)
	{
		result = 0;

		for (int i = 1; i <= MAX; i++)
		{
			vec[i].clear();
			Visited[i] = 0;
		}

		cin >> N >> M;
		if (N == 0 && M == 0) break;

		while (M--)
		{
			int x, y;
			cin >> x >> y;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}

		for (int i = 1; i <= N; i++)
		{
			if (!Visited[i])
			{
				if (DFS(i, 0)) result++;
			}
		}

		cout << "Case " << ++cnt << ": ";

		if (result == 0) cout << "No trees." << "\n";
		else if (result == 1) cout << "There is one tree." << "\n";
		else cout << "A forest of " << result << " trees." << "\n";
	}

	return 0;
}