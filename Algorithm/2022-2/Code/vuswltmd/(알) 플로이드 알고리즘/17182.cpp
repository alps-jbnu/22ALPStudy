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

int N, K;
int t[15][15];
bool visited[15];
int result = 9999999999;

void dfs(int idx, int dist, int planet)
{
	if (result < dist)
	{
		return;
	}
	if (planet == N)
	{
		result = min(result, dist);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		dfs(i, dist + t[idx][i], planet + 1);
		visited[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> t[i][j];
		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (t[i][k] + t[k][j] < t[i][j])
					t[i][j] = t[i][k] + t[k][j];
			}
		}
	}
	visited[0] = 1;

	dfs(K, 0, 1);

	cout << result;
}
