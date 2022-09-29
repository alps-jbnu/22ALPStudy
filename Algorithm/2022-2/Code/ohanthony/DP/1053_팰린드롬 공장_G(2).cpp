#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

string alpha;
int dp[51][51];

int func(int st, int en){
	if(st >= en) return 0;
	if(dp[st][en] != -1) return dp[st][en];

	//
	dp[st][en] = min({  func(st + 1, en) + 1, func(st, en - 1) + 1 , func(st+1, en-1)+(alpha[st]!=alpha[en])});

	return dp[st][en];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> alpha;
	int len = alpha.length();
	memset(dp, -1, sizeof(dp));

	// 4번 조건 충족 x
	int result = func(0, len-1);

	// 4번 조건 충족 o
	for(int i = 0; i < len-1; i++){
		for(int j = i+1; j < len; j++){
			memset(dp, -1, sizeof(dp));

			swap(alpha[i], alpha[j]);
			result = min(result, func(0, len-1) + 1);
			swap(alpha[i], alpha[j]);
		}
	}

	cout << result;
	return 0;
}
