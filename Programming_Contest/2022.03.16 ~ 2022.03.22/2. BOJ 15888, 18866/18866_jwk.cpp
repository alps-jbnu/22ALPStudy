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

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n;
vt<int> u, v, fmnu, fmxv, bmxu, bmnv;

void input() {
	cin >> n;
    u.resize(n);
    v.resize(n);
	fmnu.resize(n); fmxv.resize(n); 
	bmxu.resize(n); bmnv.resize(n);
	FOR(n) {
		cin >> u[i] >> v[i];
	}
}

void pre() {
	fmnu[0] = (u[0] > 0 ? u[0] : INF) ;
	fmxv[0] = v[0];
	FOR(i, 1, n) {
		fmnu[i] = min((u[i] > 0 ? u[i] : INF), fmnu[i - 1]);
		fmxv[i] = max(v[i], fmxv[i - 1]);
	}
	bmxu[n - 1] = u[n - 1];
	bmnv[n - 1] = (v[n - 1] > 0 ? v[n - 1] : INF);
	FOR(i, n - 2, -1, -1) {
		bmxu[i] = max(u[i], bmxu[i + 1]);
		bmnv[i] = min((v[i] > 0 ? v[i] : INF), bmnv[i + 1]);
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

	pre();

	int ans = -1;
    FOR(k, 0, n - 1 ) {
        if (!(fmnu[k] > bmxu[k + 1])) continue;
        if (!(fmxv[k] < bmnv[k + 1])) continue;

        ans = k + 1;
    }

    cout << ans;

	return 0;
}