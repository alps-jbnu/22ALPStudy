#define MX 100001
#include <iostream>
#include <algorithm>
using namespace std;

int n, s[MX];
int DP[MX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{}; i < n; i++)
        cin >> s[i];
    DP[0] = s[0];
    for (int i{1}; i < n; i++)
        DP[i] = max(DP[i - 1] + s[i], s[i]);
    cout << *max_element(DP, DP + n);

    return 0;
}