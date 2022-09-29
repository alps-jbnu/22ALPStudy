#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1000 + 1
using namespace std;

int N, M, result = 0;
int arr[MAX][MAX];
string str;

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			arr[i][j + 1] = str[j] - 48;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] != 0)
			{
				arr[i][j] = min(min(arr[i][j - 1], arr[i - 1][j]), arr[i - 1][j - 1]) + 1;
				result = max(arr[i][j], result);
			}
		}
	}

	cout << result * result;

	return 0;
}