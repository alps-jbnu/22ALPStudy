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
	for(int i = 0; i < n; i++) cin >> arr[i];
	fill(&dp[0], &dp[1004], 1);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){  // 앞의 원소가 지금까지 나왔던 원소들보다 클 경우 그 합을 구해가면서 찾는다.
			if(arr[i] > arr[j]){
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	cout << *max_element(dp, dp + n);
    return 0;
}
