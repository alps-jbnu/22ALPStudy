#include <bits/stdc++.h>
const int MAX = 100 + 10;
const int INF = 1e9;
using namespace std;

int N, M, result;
int arr[MAX][MAX];
int path[MAX][MAX];
vector<int> vec;

void Floyd()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j) continue;
				if (arr[i][j] > arr[i][k] + arr[k][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}

void Solve(int s, int e)
{
	if (!path[s][e])
	{
		vec.push_back(s);
		vec.push_back(e);
		return;
	}
	Solve(s, path[s][e]);
	vec.pop_back();
	Solve(path[s][e], e);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = INF;
		}
	}
	for (int i = 1; i <= M; i++)
	{
		int s, e, w; cin >> s >> e >> w;
		arr[s][e] = min(arr[s][e], w);
	}

	Floyd();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == INF) cout << 0 << " ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == INF) cout << 0;
			else
			{
				vec.clear();
				Solve(i, j);

				cout << vec.size() << " ";
				for (int k = 0; k < vec.size(); k++)
				{
					cout << vec[k] << " ";
				}
			}
			cout << "\n";
		}
	}
	return 0;
}