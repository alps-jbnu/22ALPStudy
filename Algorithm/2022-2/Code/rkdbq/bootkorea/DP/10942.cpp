#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 2000 + 1
using namespace std;

int N, M;
int arr[MAX];
bool b[MAX][MAX];

void Solve()
{
	for (int i = 1; i <= N; i++) // 1일 때
	{
		b[i][i] = 1;
	}

	for (int i = 1; i < N; i++) // 2일 때
	{
		if (arr[i] == arr[i + 1])
		{
			b[i][i + 1] = 1;
		}
	}

	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j <= N - i; j++)
		{
			if (arr[j] == arr[j + i] && b[j + 1][j + i - 1])
			{
				b[j][j + i] = 1;
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	scanf("%d", &M);
	memset(b, 0, sizeof(b));

	Solve();

	for (int i = 0; i < M; i++)
	{
		int S, E;
		scanf("%d %d", &S, &E);
		printf("%d\n", b[S][E]);
	}

	return 0;
}