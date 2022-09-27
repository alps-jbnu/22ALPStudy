#define MX 5001
#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[MX];
int dp[MX][MX];

int palindrome(int st, int en)
{
    int &cur{dp[st][en]};
    if (st >= en)
        return 0;
    if (cur != -1)
        return cur;

    if (arr[st] == arr[en])
        cur = palindrome(st + 1, en - 1);
    else
        cur = min(palindrome(st, en - 1), palindrome(st + 1, en)) + 1;

    return cur;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i{}; i < MX; i++)
        for (int j{}; j < MX; j++)
            dp[i][j] = -1;
    cin >> n;
    for (int i{}; i < n; i++)
        cin >> arr[i];
    cout << palindrome(0, n - 1);

    return 0;
}