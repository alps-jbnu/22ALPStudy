#define MX 2501
#include <iostream>
#include <algorithm>
using namespace std;

int n;
string arr;
int dp[MX];
bool pal[MX][MX];

int func(int en)
{
    if (!en)
        return dp[en];
    if (dp[en] != MX)
        return dp[en];
    for (int i{}; i <= en; i++)
    {
        if (pal[i][en])
        {
            if (i)
                dp[en] = min(dp[en], func(i - 1) + 1);
            else
                dp[en] = 1;
        }
    }
    return dp[en];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> arr;

    // dp[] init
    for (int i{}; i < MX; i++)
        dp[i] = MX;
    dp[0] = 1;

    // pal[][] init
    for (int i{}; i < arr.length(); i++)
        pal[i][i] = true;
    for (int i{}; i < arr.length() - 1; i++)
        if (arr[i] == arr[i + 1])
            pal[i][i + 1] = true;
    for (int i{2}; i < arr.length(); i++)
    {
        for (int j{}; j < arr.length() - i; j++)
        {
            if (pal[j + 1][j + i - 1] && arr[j] == arr[j + i])
                pal[j][j + i] = true;
        }
    }

    cout << func(arr.length() - 1);

    return 0;
}