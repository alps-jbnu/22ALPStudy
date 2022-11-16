#include <bits/stdc++.h>
const int INF = 1e9;
const int MAX = 200 + 1;
using namespace std;

int N, M, K, result = INF;
int arr[MAX][MAX];
int temp[MAX];
vector<int> vec;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			arr[i][j] = INF;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		arr[a][b] = c;
	}
	cin >> K;
	for (int i = 1; i <= K; i++)
	{
		cin >> temp[i];
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		bool flag = 1;

		for (int j = 1; j <= K; j++)
		{
			if ((arr[temp[j]][i] == INF) || (arr[i][temp[j]] == INF))
			{
				flag = 0;
				break;
			}
			cnt = max(cnt, arr[temp[j]][i] + arr[i][temp[j]]);
		}
		if (flag == 1)
		{
			if (result > cnt)
			{
				result = cnt;
				vec.clear();
				vec.push_back(i);
			}
			else if (result == cnt) vec.push_back(i);
		}
	}
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}

	return 0;
}