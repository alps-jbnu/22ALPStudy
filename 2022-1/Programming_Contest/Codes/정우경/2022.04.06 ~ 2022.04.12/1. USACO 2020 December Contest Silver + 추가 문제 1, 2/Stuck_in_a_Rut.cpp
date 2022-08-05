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

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

struct pe {
    ll x, y;
    int idx;
};

struct pn {
    ll x, y;
    int idx;
};

struct sten {
    int a, b;
    ll len, len2;
};

bool operator<(sten a, sten b) {
    return a.len > b.len;
}

int n, stopped[1010], dp[1010], en[1010];
vt<pe> ee;
vt<pn> nn;
priority_queue<sten> pq;
vt<int> adj[1010];

void init() {
    FOR(1010) {
        dp[i] = -1;
        en[i] = INF;
    }
}

void input() {
    cin >> n;
    FOR(n) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == 'E') ee.push_back({ x, y, i + 1 });
        else nn.push_back({ x, y, i + 1 });
    }
}

void f() {
    EACH(i, ee) {
        EACH(j, nn) {
            if (i.x > j.x) continue;
            if (i.y < j.y) continue;

            if (j.x - i.x > i.y - j.y) {
                en[i.idx] = min<ll>(en[i.idx], j.x - i.x);
                pq.push({ j.idx, i.idx, j.x - i.x, i.y - j.y });
            }
            if (j.x - i.x < i.y - j.y) {
                en[j.idx] = min<ll>(en[j.idx], i.y - j.y);
                pq.push({ i.idx, j.idx, i.y - j.y, j.x - i.x });
            }
        }
    }
}

void f2() {
    while (sz(pq)) {
        int a = pq.top().a, b = pq.top().b, len2 = pq.top().len2;
        pq.pop();
        
        if (stopped[b]) continue;
        if (en[a] < len2) continue;

        stopped[b] = 1;
        adj[a].push_back(b);
    }
}

int f3(int v) {
    int& ret = dp[v];
    if (ret != -1) return ret;

    ret = 1;
    EACH(i, adj[v]) {
        ret += f3(i);
    }
    return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    init();

    input();

    f();

    f2();

    FOR(i, 1, n + 1) {
        /*EACH(j, adj[i]) {
            cout << i << ' ' << j << '\n';
        }*/
        cout << f3(i) - 1 << '\n';
    }

	return 0;
}