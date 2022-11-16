#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 200 + 1;
const int INF = 1e9;
using namespace std;

int N, M;
double result = INF;
int arr[MAX][MAX];
int temp[MAX];
vector<pair<pii, int>> vec;

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
				}
			}
		}
	}
}

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
		int s, e, l; cin >> s >> e >> l;

		vec.push_back({ { s, e }, l });
		arr[s][e] = min(arr[s][e], l);
		arr[e][s] = min(arr[e][s], l);
	}
	Floyd();

	for (int i = 1; i <= N; i++)
	{
		memset(temp, 0, sizeof(temp));

		double num = 0;
		for (int j = 1; j <= N; j++) temp[j] = arr[i][j];

		for (int k = 0; k < vec.size(); k++)
		{
			int start = vec[k].first.first;
			int end = vec[k].first.second;
			int len = vec[k].second;

			if (start != i && end != i) len += min(temp[start], temp[end]);

			double n1 = max(temp[start], temp[end]);
			double n2 = (double)(len - n1) / (double)2;
			if (n2 < 0) n2 = 0;

			double n = n1 + n2;
			num = max(num, n);
		}
		result = min(result, num);
	}

	cout << fixed;
	cout.precision(1);
	cout << result;

	return 0;
}