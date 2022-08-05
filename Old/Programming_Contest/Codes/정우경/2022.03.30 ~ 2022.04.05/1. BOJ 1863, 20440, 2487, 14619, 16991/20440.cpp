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

int n, psum[2020202];
vt<pll> a;
vt<ll> b;
int ans, st, en;

void input() {
    cin >> n;
    a.resize(n);
    EACH(i, a) cin >> i.fr >> i.sc;
}

void cc() {
    EACH(i, a) {
        b.push_back(i.fr);
        b.push_back(i.sc);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    FOR(n) {
        a[i].fr = lower_bound(all(b), a[i].fr) - b.begin();
        a[i].sc = lower_bound(all(b), a[i].sc) - b.begin();
    }
}

void makingPsum() {
    EACH(i, a) {
        psum[i.fr]++;
        psum[i.sc]--;
    }

    FOR(i, 1, 2000001)
        psum[i] += psum[i - 1];
}

void f() {
    int bit = 0;
    FOR(2000001) {
        if (bit && psum[i] != ans) {
            bit = 0;
            en = i;
        }

        if (psum[i] > ans) {
            ans = psum[i];
            bit = 1, st = i;
        }
    }
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

    cc();

    makingPsum();

    f();

    cout << ans << '\n' << b[st] << ' ' << b[en] << '\n';

	return 0;
}