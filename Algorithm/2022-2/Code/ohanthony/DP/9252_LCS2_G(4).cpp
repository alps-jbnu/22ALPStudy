#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int dp[1005][1005]; // 0.1초 라는 조건과 string STL 특성상 시간초과 발생

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int len1 = s1.length();
	int len2 = s2.length();

	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int row = len1;
	int col = len2;
	string s = "";
	while(row != 0 && col != 0){
		if(dp[row][col] == dp[row-1][col]) row--;
		else if(dp[row][col] == dp[row][col-1]) col--;
		else {
			row--; col--;
			s += s1[row];
		}
	}

	cout << dp[len1][len2] << '\n';
	if(s.size() > 0){
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
	return 0;
}
