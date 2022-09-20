#define MX 51
#include <iostream>
#include <algorithm>
using namespace std;

int n;
string str[MX*MX];
int dp[MX][MX];

int palindrome(int idx, int st, int en)
{
    int &cur{dp[st][en]};
    if (st >= en)
        return 0;
    if (cur != -1)
        return cur;

    if (str[idx][st] == str[idx][en])
        cur = palindrome(idx, st + 1, en - 1);
    else
        cur = min(palindrome(idx, st, en - 1), palindrome(idx, st + 1, en)) + 1;

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
    cin>>str[0];
    for(int i{}; i<n; i++) str[i] = str[0];
    for(int i{}; i<n; i++) for(int j{}; j<n; j++)
    cout << palindrome(0, n - 1);

    return 0;
}