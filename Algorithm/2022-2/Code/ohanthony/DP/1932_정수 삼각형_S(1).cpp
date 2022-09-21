#include<iostream>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int result;
int n; // 삼각형의 크기
int arr[505][505];
int dp[505][505]; // 아래층에서 선택된 수의 합의 최대값 저장하는 테이블

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cin >> arr[i][j];
		}
	}

	if(n == 1){ // n == 1인 경우 dp점화식까지 갈 필요없다.
		cout << arr[0][0];
		return 0;
	}

	dp[0][0] = arr[0][0];
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= i; j++){
			dp[i][j] = arr[i][j] + max(dp[i-1][j-1], dp[i-1][j]);

			result = max(result, dp[i][j]);
		}
	}

	cout << result;
	return 0;
}