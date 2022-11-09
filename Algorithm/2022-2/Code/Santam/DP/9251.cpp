#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001]{};
string s_1, s_2;


int LCS(int f, int s) 
{
	if (f <1 || s < 1 ) return 1; //초기값 1: 탐색을 했지만 0인경우 0: 탐색을 안한 경우
	if (dp[f][s]) return dp[f][s]; //dp에 값 존재할시 반환
	if (s_1[f - 1] == s_2[s - 1]) //마지막 문자를 비교해 같을 시 LCS(f-1,s-1)까지의 문자열에서 최대값에 +1을 해준다
	{
		dp[f][s]=LCS(f - 1, s - 1) + 1;
		return dp[f][s];
	}
	dp[f][s] = max(LCS(f - 1, s), LCS(f, s - 1)); //마지막 문자가 다를시에 LCS(f-1,s)와 LCS(f,s-1)의 최대값중에 큰거 선택
	return dp[f][s];
} // 마지막 문자끼리 재귀적으로 비교하면서 DP수행

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> s_1 >> s_2;
	cout << LCS(s_1.length(), s_2.length())-1; // 초기값 문제로 마지막 1을 빼주어야됨

	return 0;
}