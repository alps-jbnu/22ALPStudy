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

int N;
string seq;
string seq2;
int dp[55][55];
int result = 150;

void func(int s, int e)
{
	if (s == e) return;
	if (s > e) return;
	if (dp[s][e]) return;
	else
	{
		if (seq2[s] == seq2[e])
		{
			func(s + 1, e - 1);
			dp[s][e] = dp[s + 1][e - 1];
		}
		else
		{
			func(s + 1, e);
			func(s, e - 1);
			func(s + 1, e - 1);
			dp[s][e] = min({ dp[s + 1][e] + 1, dp[s][e - 1] + 1, dp[s + 1][e - 1] + 1 });
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> seq;
	seq2 = seq;

	func(0, seq2.length()-1);

	if (result > dp[0][seq2.length()-1])
	{
		result = dp[0][seq2.length()-1];
	}

	for (int i = 0; i < seq2.length(); i++)
	{
		for (int j = 0; j < seq2.length(); j++)
		{
			if (i == j) continue;
			
			char T;
			// 위치교환
			T = seq2[i];
			seq2[i] = seq2[j];
			seq2[j] = T;

			func(0, seq2.length()-1);
			// 함수를 돌린다

			if (result > dp[0][seq2.length()-1])
			{
				result = dp[0][seq2.length()-1]+1 ;
			}

			seq2 = seq;
			// 다시 원래 배열로 초기화 

			for (int i = 0; i <= 54; i++)
			{
				for (int j = 0; j <= 54; j++)
				{
					dp[i][j] = 0;
				}
			}
			// dp 초기화
		}
	}

	cout << result;
}



