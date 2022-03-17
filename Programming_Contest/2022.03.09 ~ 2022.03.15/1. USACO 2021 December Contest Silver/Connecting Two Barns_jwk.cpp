#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define EXPAND( x ) x // Use this if MS Visual Studio doesn't expand __VA_ARGS__ correctly
#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) EXPAND( GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1) )
#define FOR(...) EXPAND( F_ORC(__VA_ARGS__ )(__VA_ARGS__) )
#define EACH(x, a) for (auto& x : a)

const ll INF = 1e18 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, m;
vt<int> adj[101010];
set<int> co[101010], rco[101010];
int visited[101010], cCnt, label[101010];
ll d1[101010], dn[101010];

void init() {
    FOR(101010) {
        adj[i].clear();
        co[i].clear();
        rco[i].clear();
        visited[i] = 0;
        label[i] = 0;
        d1[i] = dn[i] = INF;
    }
    cCnt = 0;
}

void input() {
    cin >> n >> m;
    FOR(m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int v) {
    visited[v] = 1;
    co[cCnt].insert(v);
    rco[cCnt].insert(-v);
    label[v] = cCnt;

    EACH(u, adj[v]) {
        if (visited[u]) continue;
        dfs(u);
    }
}

void f() {
    int st = label[1], en = label[n];
    
    FOR(cCnt) {
        if (i == st || i == en) continue;
        
        EACH(j, co[i]) {
            ll k1 = *co[st].lower_bound(j);
            ll k2 = -*rco[st].lower_bound(-j);

            if (k1 != *co[st].end())
                d1[i] = min(d1[i], (k1 - j) * (k1 - j));
            if (k2 != -*rco[st].end())
                d1[i] = min(d1[i], (k2 - j) * (k2 - j));
        }

        EACH(j, co[i]) {
            ll k1 = *co[en].lower_bound(j);
            ll k2 = -*rco[en].lower_bound(-j);
            
            if (k1 != *co[en].end())
                dn[i] = min(dn[i], (k1 - j) * (k1 - j));
            if (k2 != -*rco[en].end())
                dn[i] = min(dn[i], (k2 - j) * (k2 - j));
            
        }
    }

    EACH(j, co[st]) {
        ll k1 = *co[en].lower_bound(j);
        ll k2 = -*rco[en].lower_bound(-j);
        
        if (k1 != *co[en].end()) 
            d1[en] = min(d1[en], (k1 - j) * (k1 - j));
        if (k2 != -*rco[en].end())
            d1[en] = min(d1[en], (k2 - j) * (k2 - j));
    }
}

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
    freopen("/Users/jeongwoo-kyung/Programming/PS-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/PS-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;

    FOR(tc) {
        init();

        input();

        FOR(i, 1, n + 1) {
            if (visited[i]) continue;
            dfs(i); cCnt++;
        }

        if (label[1] == label[n]) {
            cout << 0 << '\n';
            continue;
        }

        f();

        ll ans = d1[label[n]];
        FOR(cCnt) {
            if (i == label[1] || i == label[n]) continue;
            ans = min(ans, d1[i] + dn[i]);
        }
        
        cout << ans << '\n';
    }

	return 0;
}
