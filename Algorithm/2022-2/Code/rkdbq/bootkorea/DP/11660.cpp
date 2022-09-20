#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int x1, x2, y1, y2;
int arr[1025][1025];
int dp[1025][1025];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	while (M--)
	{
		cin >> x1 >> x2 >> y1 >> y2;

		cout << dp[y1][y2] - dp[x1 - 1][y2] - dp[y1][x2 - 1] + dp[x1 - 1][x2 - 1] << "\n";
	}

	return 0;
}