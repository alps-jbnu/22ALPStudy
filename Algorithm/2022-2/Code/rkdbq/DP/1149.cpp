#define MX 1001
#define R 0
#define G 1
#define B 2
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cost[MX][3];
int DP[MX][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{}; i < n; i++)
    {
        for (int j{}; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }
    for (int i{}; i < 3; i++)
    {
        DP[0][i] = cost[0][i];
    }
    for (int i{1}; i < n; i++)
    {
        DP[i][R] = min(DP[i - 1][G], DP[i - 1][B]);
        DP[i][G] = min(DP[i - 1][B], DP[i - 1][R]);
        DP[i][B] = min(DP[i - 1][R], DP[i - 1][G]);
        for (int j{}; j < 3; j++)
        {
            DP[i][j] += cost[i][j];
        }
    }

    cout << *min_element(DP[n - 1], DP[n - 1] + 3);

    return 0;
}