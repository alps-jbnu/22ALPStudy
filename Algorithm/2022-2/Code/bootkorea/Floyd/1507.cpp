#include <iostream>
#include <cstring>
using namespace std;

int N, result;
int arr[21][21];
int road[21][21];

void Floyd()
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i == j || j == k || i == k) continue;
				else if (arr[i][j] > arr[i][k] + arr[k][j])
				{
					result = -1;
					return;
				}
				else if (arr[i][j] == arr[i][k] + arr[k][j]) road[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	memset(road, true, sizeof(road));
	Floyd();

	if (result != -1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (road[i][j]) result += arr[i][j];
			}
		}
	}

	if (result == -1) cout << result;
	else cout << result / 2;

	return 0;
}