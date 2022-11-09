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

string word1;
string word2;

int dp[1005][1005];
// 표를 만들어서 푼다. 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> word1;
	cin >> word2;

	for (int i = 1; i <= word1.length(); i++)
	{
		for (int j = 1; j <= word2.length(); j++)
		{
			if (word1[i-1] == word2[j-1])
			{
				dp[j][i] = dp[j - 1][i - 1] + 1;
			}
			else
			{
				dp[j][i] = max( dp[j - 1][i], dp[j][i - 1]);
			}
		}
	}

	for (int i = 0; i <= word1.length(); i++)
	{
		for (int j = 0; j <= word2.length(); j++)
		{
			cout << dp[i][j];
		}
		cout << endl;
	}

	cout << dp[word2.length()][word1.length()];


}
