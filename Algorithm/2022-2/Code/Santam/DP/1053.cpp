#include <bits/stdc++.h>

using namespace std;

int dp[51][51]{},res;
string s,temp_s;

int rec(int f, int s)
{
	if (dp[f][s]!=-1) return dp[f][s];
	if (s - f < 2)
	{
		if (temp_s[f - 1] != temp_s[s - 1]) dp[f][s] = 1; //두값이 다를때 팰린드롬이 아니기에 추가나,삽입,교환 어떤 경우로도 +1 연산 시행
		else dp[f][s] = 0;
		dp[f][f] = 0;
		dp[s][s] = 0;
		return dp[f][s];
	} //종료조건
	int op = 0;
	if (temp_s[f - 1] != temp_s[s - 1]) op=1;
	dp[f][s] = min(min(rec(f, s - 1)+1, rec(f + 1, s)+1),rec(f+1,s-1)+op);
	//양끝의 서로 다른 값이 삽입,제거 연산을 통해 같아졌다면 그 부분은 팰린드롬이므로 고려해줄 필요없음 << 과정을 재귀적으로 호출
	//양끝이 다른데 문자하나를 교환하는 경우에는 양끝의 길이를 하나씩 줄인 막대에서 도출된 최소값에서 +1 (문자같으면 +1은 제외)

	return dp[f][s];
}


int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> s;
	temp_s = s;
	memset(dp, -1, sizeof(int) * 51 * 51);
	res = rec(1, s.length());
	for (int i = 0; i < s.length()-1; i++)
	{
		for (int j = i+1; j < s.length(); j++)
		{
			memset(dp, -1, sizeof(int) * 51 * 51);
			temp_s = s;
			swap(temp_s[i], temp_s[j]);
			res=min(rec(1, temp_s.length())+1, res); //swap할때의 연산횟수 +1
		}
	}
	cout << res;
	return 0;
}