#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;

int N, M;
int arr[101][101];

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) // 비용 설정
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = INF;
		}
		arr[i][i] = 0; // 제자리 노코스트
	}

	for (int i = 1; i <= M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		arr[a][b] = min(c, arr[a][b]);
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
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == INF) arr[i][j] = 0;

			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}