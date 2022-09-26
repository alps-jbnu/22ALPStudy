#define MX 1002
#include <iostream>
#include <algorithm>
using namespace std;

string str[2];
int DP[MX][MX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i{}; i < 2; i++)
    {
        cin >> str[i];
        str[i] = ' ' + str[i];
    }
    for (int i{1}; i <= str[0].length(); i++)
    {
        for (int j{1}; j <= str[1].length(); j++)
        {
            if (str[0][i] == str[1][j])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
        }
    }

    cout << DP[str[0].length() - 1][str[1].length() - 1];

    return 0;
}