#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1001];
int DP[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{}; i < n; i++)
        cin >> a[i];
    for (int i{}; i < n; i++)
    {
        DP[i] = a[i];
        for (int j{}; j < i; j++)
        {
            if (a[i] > a[j])
            {
                DP[i] = max(DP[i], DP[j] + a[i]);
            }
        }
    }
    cout << *max_element(DP, DP + n);

    return 0;
}