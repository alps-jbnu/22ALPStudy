#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll Q; cin>>Q;
    unordered_map<string, priority_queue<ll>> pqs;
    pqs.reserve(Q);
    ll ans=0;
    // 모든 쿼리에 대한 k의 합을 X라 하면, X는 100만을 넘지 않는다.
    // X가 우선순위 큐에 들어갈 수 있는 최대 원소의 개수이므로,
    // 시간복잡도는 O(QlogX)이 된다.
    for (ll q=0;q<Q;++q)
    {
        ll query; string name;
        cin>>query>>name;
        if (query==1)
        {
            ll k; cin>>k;
            for (ll i=0;i<k;++i)
            {
                ll Ci; cin>>Ci;
                pqs[name].push(Ci);
            }
        }
        else
        {
            ll b; cin >> b;
            for (ll i=0;i<b&&!pqs[name].empty();++i)
            {
                ans+=pqs[name].top();
                pqs[name].pop();
            }
        }
    }
    cout << ans;
}
