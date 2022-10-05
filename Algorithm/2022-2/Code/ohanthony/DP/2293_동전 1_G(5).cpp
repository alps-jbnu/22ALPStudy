#include<iostream>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int dp[10005] = { 1, };
int n, k;
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		int coin;
		cin >> coin;
		for(int j = coin; j <= k; j++){
			dp[j] += dp[j - coin];
		}
	}
	cout << dp[k];
	return 0;
}