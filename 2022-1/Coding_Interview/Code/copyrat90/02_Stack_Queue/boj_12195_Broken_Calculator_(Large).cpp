#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
constexpr bool ndebug = false;
#else
constexpr bool ndebug = true;
#endif

#define debugf(...) if constexpr (!ndebug) {printf("[DEBUG] "); printf(__VA_ARGS__);}

using ll = long long;
constexpr ll INF = 2e18+7;

struct Elem
{
    Elem(ll lastTerm) : lastTerm(lastTerm) {}

    ll lastTerm, prevAcc = 1;
    ll clicks = 1;
    bool isLastClickMul = false;

    ll getNum() const { return lastTerm * prevAcc; }
    
    void clickDigit(ll digit)
    {
        lastTerm *= 10;
        lastTerm += digit;
        ++clicks;
        isLastClickMul = false;
    }

    void clickMul()
    {
        prevAcc *= lastTerm;
        lastTerm = 0;
        ++clicks;
        isLastClickMul = true;
    }
};

// INF: Impossible
ll bfs(const bitset<10>& alive, ll X)
{
    vector<ll> vis(X+1, INF);
    queue<Elem> q;
    // [실수2] X가 i보다 작을때는 pass 해야 segfault 안낸다...
    for (ll i=1;i<=9&&i<=X;++i)
        if (alive[i])
        {
            // [실수1] 까먹고 1의자리수 방문처리 안했다...
            vis[i] = 1;
            q.push(Elem(i));
        }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        // 숫자 클릭
        for (ll i=0;i<=9;++i)
            if (alive[i])
            {
                auto candi = cur;
                candi.clickDigit(i);
                if (candi.getNum() > X)
                    continue;
                // [실수3] k*1 하면 k가 이미 방문돼있어서 무조건 스킵되는데, 이러면 *11 을 수행할 수 없다.
                // 이번 항이 1인 경우에는, 중복을 허용해 bfs 돌리자.
                // (근데 j가 1이 아니라도, k*j 했는데 k*j가 이미 방문돼있어서 스킵되는데, k*(10j+t)  찾아야하는 경우는 전부 틀릴거같은데, 데이터가 약한가?)
                if (candi.clicks >= vis[candi.getNum()] && candi.lastTerm != 1)
                    continue;
                if (candi.clicks < vis[candi.getNum()])
                    vis[candi.getNum()] = candi.clicks;
                q.push(candi);
            }

        // 곱하기 클릭
        if (!cur.isLastClickMul && cur.lastTerm != 1)
        {
            auto candi = cur;
            candi.clickMul();
            q.push(candi);
        }
    }

    return vis[X]+1;
}

int main()
{
    if constexpr (ndebug)
        cin.tie(0)->sync_with_stdio(0);

    ll T; cin >> T;
    for (ll i=1;i<=T;++i)
    {
        bitset<10> alive;
        for (ll i=0;i<10;++i)
        {
            ll aliveInp;  cin >> aliveInp;
            alive[i] = (bool)aliveInp;
        }

        ll X; cin >> X;
        const ll res = bfs(alive,X);
        cout << "Case #" << i << ": ";
        if (res == INF+1)
            cout << "Impossible\n";
        else
            cout << res << '\n';
    }
}
