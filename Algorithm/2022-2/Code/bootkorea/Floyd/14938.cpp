#include <iostream>
#include <algorithm>
#define MAX 100 + 1
#define INF 987654321
using namespace std;

int N, M, R, result = 0;
int arr[MAX], dist[MAX][MAX];

int main()
{
	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j) dist[i][j] = INF;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i]; // t
	}

	for (int i = 0; i < R; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;

		dist[a][b] = l;
		dist[b][a] = l;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int temp = arr[i];

		for (int j = 0; j <= N; j++)
		{
			if (i != j && dist[i][j] <= M) temp += arr[j];
		}
		result = max(result, temp);
	}

	cout << result;

	return 0;
}