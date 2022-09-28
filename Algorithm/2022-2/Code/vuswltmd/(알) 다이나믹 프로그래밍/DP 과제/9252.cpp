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

int dp[1001][1001];
string result;

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
			if (word1[i - 1] == word2[j - 1])
			{
				dp[j][i] = dp[j - 1][i - 1] + 1;
			}
			else
			{
				if (dp[j - 1][i] >= dp[j][i - 1])
				{
					dp[j][i] = dp[j - 1][i];
				}
				else
				{
					dp[j][i] = dp[j][i - 1];
				}
			}
		}
	}

	int col = word2.size();
	int row = word1.size();

	while (dp[col][row])
	{
		if (dp[col][row] == dp[col - 1][row]) {
			col--;
		}
		else if (dp[col][row] == dp[col][row - 1]) {
			row--;
		}
		else {
			result += word1[row - 1];
			row--, col--;
		}
	}

	/*for (int col = 0; col <= word1.length(); col++)
	{
		for (int row = 0; row <= word2.length(); row++)
		{
			cout << dp[col][row];
		}
		cout << endl;
	}*/

	cout << dp[word2.length()][word1.length()] << '\n';
	if (result.size() > 0) {
		reverse(result.begin(), result.end());
		cout << result << endl;
	}

}
