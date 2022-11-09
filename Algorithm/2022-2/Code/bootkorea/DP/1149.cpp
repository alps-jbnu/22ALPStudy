#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int result = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) // 계산식 수행을 위해 필요한 범위 설정
	{
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2]; // 빨 초 파 비용 입력

		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]); // 빨 + (초 파 중 작은 거)
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]); // 초 + (빨 파 중 작은 거)
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]); // 파 + (빨 초 중 작은 거)
	}

	result = min(min(dp[N][0], dp[N][1]), dp[N][2]); // 빨 초 파 스타트 중 어떤 게 작아

	cout << result << "\n";

	return 0;
}