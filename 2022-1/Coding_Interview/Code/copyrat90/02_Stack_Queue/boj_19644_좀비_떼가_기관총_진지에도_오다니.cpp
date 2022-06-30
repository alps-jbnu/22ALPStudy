#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
constexpr bool ndebug = false;
#else
constexpr bool ndebug = true;
#endif

#define debug(x) if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n'

using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll L, ML, MK, Cammo;
    cin>>L>>ML>>MK>>Cammo;

    vector<ll> Z(L);
    for (ll& z : Z)
        cin>>z;
    
    bool survive = true;
    // 마지막으로 누적 데미지를 적용할 idx 를 저장
    queue<ll> q;
    for (ll nearPos=0; nearPos<L;++nearPos)
    {
        debug(nearPos);
        // 누적 데미지를 적용할 idx 중 지나간 idx 는 pop()
        while (!q.empty() && q.front() < nearPos)
        {
            debug(q.front());
            q.pop();
        }
        
        auto& z = Z[nearPos];
        z -= q.size() * MK;
        debug(z);
        // [ERR] 바로 앞에 적이 없더라도 항상 총을 쏘고 있어야 한다!!!!
        // 반례: 멀리 떨어진 적을 미리 죽여놓지 않으면 망하는 상황도 있다.
        // if (z <= 0)
        //     continue;
        
        // 지뢰 써야하는 상황
        if (z > MK)
        {
            if (Cammo <= 0)
            {
                survive=false;
                break;
            }
            Cammo--;
            debug(Cammo);
        }
        // 총으로 가능한 상황
        else
        {
            // 마지막 사거리 idx 저장
            q.push(nearPos + ML - 1);
            debug(q.back());
        }
    }

    cout << (survive?"YES":"NO");
}
