#include <bits/stdc++.h>
using namespace std;

using ll = long long;

unordered_map<ll, ll> dp;
ll P, Q;

// DP 최적화로, 대략 O(logN) 개의 공간을 방문하게 된다.
// DP가 없으면 O(N^{log_{min(P,Q)} 2}) 가 되는 것 같다. 마스터 정리 참고.
ll A(ll i)
{
    if (i == 0)
        return 1;

    auto it = dp.find(i);
    if (it != dp.end())
        return it->second;
    
    return dp[i] = A(i/P) + A(i/Q);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll N;
    cin >> N >> P >> Q;
    cout << A(N);
}
