#include <bits/stdc++.h>

using namespace std;

string dp[1001][1001]{};
string s_1, s_2;


string LCS(int f, int s)
{
	if (f < 1 || s < 1) return "T"; //초기값 "T": 탐색을 했지만 0인경우 NULL: 탐색을 안한 경우
	if (!dp[f][s].empty()) return dp[f][s]; //dp에 값 존재할시 반환
	if (s_1[f - 1] == s_2[s - 1]) //마지막 문자를 비교해 같을 시 LCS(f-1,s-1)까지의 문자열에서 최대값에 +1을 해준다
	{
		dp[f][s] = LCS(f - 1, s - 1) + s_1[f - 1];
		return dp[f][s];
	}
	string t_1 = LCS(f - 1, s), t_2 = LCS(f, s - 1); //마지막 문자가 다를시에 LCS(f-1,s)와 LCS(f,s-1)의 최대값중에 큰거 선택
	t_1.length() > t_2.length() ? dp[f][s] = t_1 : dp[f][s] = t_2;
	return dp[f][s];
} // 마지막 문자끼리 재귀적으로 비교하면서 DP수행

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> s_1 >> s_2;
	string s = LCS(s_1.length(), s_2.length());
	cout << s.length() - 1 << "\n"; // 초기값 문제로 마지막 1을 빼주어야됨
	for (int i = 1; i < s.length(); i++)
	{
		cout << s[i];
	}
	return 0;
}