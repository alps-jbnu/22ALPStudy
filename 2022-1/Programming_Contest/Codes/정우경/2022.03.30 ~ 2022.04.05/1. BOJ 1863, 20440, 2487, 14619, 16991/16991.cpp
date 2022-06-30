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

struct wv {
    double w;
    int v;
};

int n;
pll a[16];
double adj[16][16], dp[16][(1 << 16)];

void input() {
    cin >> n;
    FOR(n) cin >> a[i].fr >> a[i].sc;
}

void graphModeling() {
    FOR(n) {
        FOR(j, n) {
            if (i == j) continue;
            double w = sqrt(pow(a[i].fr - a[j].fr, 2) + pow(a[i].sc - a[j].sc, 2));
            adj[i][j] = adj[j][i] = w;
        }
    }
}

double f(int v, int bit) {
    double& ret = dp[v][bit];
    if (ret > 0) return ret;
    if (bit == (1 << n) - 1) return ret = adj[v][0];

    ret = INF;

    FOR(n) {
        if (bit & (1 << i)) continue;
        ret = min(ret, f(i, bit | (1 << i)) + adj[v][i]);
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

    input();

    graphModeling();

    cout << fixed;
    cout.precision(6);
    cout << f(0, 1);

	return 0;
}