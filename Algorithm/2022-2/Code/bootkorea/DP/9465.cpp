#include <iostream>
#include <algorithm>
using namespace std;

int T, n;
int dp[2][100001];
int result[2][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) // 케이스 수 T가 0이 될 때까지
	{
		cin >> n; // 각 케이스의 n값 입력

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++) // dp[i][j]를 범위에 맞게 입력받음
			{
				cin >> dp[i][j];
			}
		}

		result[0][0] = dp[0][0];
		result[1][0] = dp[1][0]; // result에 dp값 처음 값 복사

		for (int i = 1; i < n; i++) // i번째까지 값들 중, 2칸 뒤의 i +- 1 의 값들까지 확인하여 최대 확인
		{
			result[0][i] = max(result[1][i - 1], result[1][i - 2]) + dp[0][i];
			result[1][i] = max(result[0][i - 1], result[0][i - 2]) + dp[1][i];
		}

		cout << max(result[0][n - 1], result[1][n - 1]) << "\n"; // n까지의 최댓값을 출력
	}

	return 0;
}