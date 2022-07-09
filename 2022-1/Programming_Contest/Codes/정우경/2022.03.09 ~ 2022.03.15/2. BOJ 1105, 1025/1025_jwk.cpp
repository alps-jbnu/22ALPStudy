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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 1, 1, -1, -1 };
const int dx[] = { 1, -1, 1, -1 };

int n, m, a[15][15];
ll ans = -1;
set<ll> s;
ll p10[14];

void init() {
    p10[0] = 1;
    FOR(i, 1, 14) p10[i] = 10 * p10[i - 1];

    FOR(i, 100001) {
        s.insert((ll)i * i);
    }
}

void input() {
    cin >> n >> m;
    FOR(n) {
        string s; cin >> s;
        FOR(j, m) {
            a[i][j] = s[j] - '0';
        }
    }
}

void f3(vt<int> res) {
    ll v1 = 0;
    FOR(i, sz(res)) {
        v1 += p10[i] * res[i];
    }

    if (s.find(v1) != s.end()) ans = max(ans, v1);
}

void f2(int b, int c) {
    FOR(k, 4) {
        FOR(n) {
            FOR(j, m) {
                vt<int> res;
                int y = i, x = j;
            
                while (0 <= y && y < n && 0 <= x && x < m) {
                    res.push_back(a[y][x]);
                    y += b * dy[k], x += c * dx[k];
                    f3(res);
                }
            }
        }
    }
}

void f() {
    FOR(i, 0, n + 1) {
        FOR(j, 0, m + 1) {
            if (i == 0 && j == 0) continue;
            f2(i, j);
        }
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

    init();

	input();

    if (n == 1 && m == 1) {
        if (s.find(a[0][0]) != s.end()) cout << a[0][0];
        else cout << -1;
        return 0;
    }

    f();
    
    cout << ans;

	return 0;
}