#include <iostream>
#define INF 987654321
using namespace std;

int N, M, result = 0;
int arr[101][101];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = INF;
		}
		arr[i][i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		arr[a][b] = arr[b][a] = 1;
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	int temp = INF;
	for (int i = 0; i < N; i++)
	{
		int idx = 0;

		for (int j = 0; j < N; j++)
		{
			idx += arr[i][j];
		}

		if (temp > idx)
		{
			temp = idx;
			result = i;
		}
	}

	cout << result + 1;

	return 0;
}