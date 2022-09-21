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

int N, M;
const int INF = 200 * 1000 * 1000 * 2;
int t[205][205];
int ans[205];
int fri[205];
vector<int> vil;
int K;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			t[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, time;
		cin >> a >> b >> time;

		t[a][b] = time;
	}

	for (int i = 1; i <= N; i++)
	{
		t[i][i] = 0;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (t[i][k] + t[k][j] < t[i][j])
					t[i][j] = t[i][k] + t[k][j];
			}
		}
	}

	cin >> K;

	for (int i = 1; i <= K; i++)
	{
		cin >> fri[i];
	}

	priority_queue<pair<int, int>, 
		vector<pair<int, int>>, 
		greater<pair<int, int>>> pq;

	for (int i = 1; i <= N; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= K; j++)
		{
			if ((tmp < t[fri[j]][i] + t[i][fri[j]]) && (t[fri[j]][i] < INF) && (t[i][fri[j]] < INF))
			{
				tmp = t[fri[j]][i] + t[i][fri[j]];
			}
		}
		pq.push({ tmp, i });
	}

	int ans_time;

	cout << pq.top().second << ' ';
	ans_time = pq.top().first; pq.pop();

	while (!pq.empty() && pq.top().first == ans_time) {
		cout << pq.top().second << ' ';
		pq.pop();
	}
	return 0;
}
