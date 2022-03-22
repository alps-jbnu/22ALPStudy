#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, mid;
pll a[44], en;
multiset<pll> mpl[25];
map<pll, int> mpr[25];
ll ans[44];

void input() {
    cin >> n;
    cin >> en.fr >> en.sc;
    FOR(i, n) cin >> a[i].fr >> a[i].sc;
}

pll x;
int cnt;

void f(int p, int up) {
	if (p == up + 1) {
		if (up == mid) {
			auto it = mpl[cnt].find(x);
			mpl[cnt].insert(x);
		}
		else {
			auto it = mpr[cnt].find(x);
			if (it == mpr[cnt].end()) mpr[cnt].insert({ x, 1 });
			else it->sc++;
		}
		return;
	}

	f(p + 1, up);
	x.fr += a[p].fr, x.sc += a[p].sc, cnt++;
	f(p + 1, up);
	x.fr -= a[p].fr, x.sc -= a[p].sc, cnt--;
}

void f2() {
	FOR(l, 0, 21) {
		EACH(i, mpl[l]) {
			pll rr = { en.fr - i.fr, en.sc - i.sc };

			FOR(r, 0, 21) {
				auto it = mpr[r].find(rr);

				if (it != mpr[r].end())
					ans[l + r] += it->sc;
			}
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

	if (n == 1) {
		if (a[0] == en) cout << 1;
		else cout << 0;
		return 0;
	}

	mid = (0 + n - 1) / 2;

	f(0, mid);
	f(mid + 1, n - 1);
	
	f2();

	FOR(i, 1, n + 1)
		cout << ans[i] << '\n';

	return 0;
}