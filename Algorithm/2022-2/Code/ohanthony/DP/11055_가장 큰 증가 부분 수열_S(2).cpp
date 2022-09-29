#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int arr[1005];
int dp[1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	int result = arr[0];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){  // 앞의 원소가 지금까지 나왔던 원소들보다 클 경우 그 합을 구해가면서 찾는다.
			if(arr[j] < arr[i]){
				dp[i] = max(dp[i], arr[i]+dp[j]);
			}
			result = max(result, dp[i]);
		}
	}

	cout << result;
    return 0;
}
