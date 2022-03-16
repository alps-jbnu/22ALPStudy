#include <bits/stdc++.h>
using namespace std;

using ll=long long;

ll N, P, Q, X, Y;
unordered_map<ll, ll> dp;

ll A(ll i)
{
    if (i <= 0)
        return 1;
    auto it = dp.find(i);
    if (it != dp.end())
        return it->second;
    return dp[i] = A(i/P-X) + A(i/Q-Y);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> P >> Q >> X >> Y;
    cout << A(N);
}
