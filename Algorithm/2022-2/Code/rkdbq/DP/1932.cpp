#include <iostream>
#include <algorithm>
using namespace std;

int n;
int tri[501][501];
int DP[501][501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{}; i < n; i++)
    {
        for (int j{}; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }

    DP[0][0] = tri[0][0];
    for (int i{1}; i < n; i++)
    {
        for (int j{}; j <= i; j++)
        {
            if (j == 0)
                DP[i][j] = DP[i - 1][j];
            else if (j == i)
                DP[i][j] = DP[i - 1][j - 1];
            else
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]);
            DP[i][j] += tri[i][j];
        }
    }
    cout << *max_element(DP[n - 1], DP[n - 1] + n);

    return 0;
}