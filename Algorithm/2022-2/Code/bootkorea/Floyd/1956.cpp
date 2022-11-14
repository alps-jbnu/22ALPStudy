#include <iostream>
#include <algorithm>
#define MAX 400 + 1
#define INF 987654321
using namespace std;

int V, E;
int arr[MAX][MAX];

int main()
{
	cin >> V >> E;

	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			arr[i][j] = INF;
		}
	}

	for (int i = 1; i <= E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		arr[a][b] = c;
	}

	for (int k = 1; k <= V; k++)
	{
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (arr[i][j] > arr[i][k] + arr[k][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	int temp = INF;
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (i == j) continue;
			if (arr[i][j] != INF && arr[j][i] != INF)
			{
				temp = min(temp, arr[i][j] + arr[j][i]);
			}
		}
	}

	if (temp == INF)	cout << -1;
	else cout << temp;

	return 0;
}