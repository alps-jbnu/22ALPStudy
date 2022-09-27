#define MX 10001
#include <iostream>
using namespace std;

int n;
int coins[21];
int cases[MX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cases[0] = cases[1] = 1;
    for (int i{2}; i < MX; i++)
    {
        for (int j{}; j < n; j++)
        {
            if (i >= coins[j])
                cases[i] += cases[i - coins[j]];
        }
    }
    cout << cases[n];

    return 0;
}