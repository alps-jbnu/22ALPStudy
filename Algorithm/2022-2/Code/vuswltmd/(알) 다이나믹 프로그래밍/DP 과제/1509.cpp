#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

string seq;
bool dp[2505][2505];
int fcount[2505];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> seq;
	int SL = seq.length();
	
	// 자기 자신은 1임
	for (int i = 0; i < SL; i++)
	{
		dp[i][i] = 1;
	}

	// 바로 뒤와 같으면 1임; // 2개 검사할 때
	for (int i = 0; i < SL - 1; i++)
	{
		if (seq[i] == seq[i + 1])
		{
			dp[i][i + 1] = 1;
		}
	}
	
	// 3개 이상 검사할 때
	for (int i = 1; i < SL; i++)
	{
		for (int j = 0; j < SL - i; j++)
		{
			if (seq[j] == seq[j + i] && dp[j + 1][j + i - 1])
			{
				dp[j][j + i] = 1;
			}
		}
	}

	//fcount[0] = 0;

	for (int i = 0; i < SL; i++)
	{
		fcount[i] = 987654321;
		for (int j = 0; j <= i; j++)
		{
			if (dp[j][i])
			{
				fcount[i] = min(fcount[i], fcount[j - 1] + 1);
			}
		}
	}

	cout << fcount[SL - 1];
	return 0;
}



