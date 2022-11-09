#define MX 101
#include <iostream>
#include <algorithm>
using namespace std;

string str[3];
int len[3];
int dp[MX][MX][MX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i{}; i < 3; i++)
    {
        cin >> str[i];
        str[i] = ' ' + str[i];
        len[i] = str[i].length();
    }

    for (int i{1}; i < len[0]; i++)
    {
        for (int j{1}; j < len[1]; j++)
        {
            for (int k{1}; k < len[2]; k++)
            {
                if (str[0][i] == str[1][j] && str[1][j] == str[2][k])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
                }
            }
        }
    }
    cout << dp[len[0] - 1][len[1] - 1][len[2] - 1];

    return 0;
}