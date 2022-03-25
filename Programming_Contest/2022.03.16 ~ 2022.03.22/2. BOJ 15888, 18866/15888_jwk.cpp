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

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    set<ll> p2;
    for (ll i = 2; i < INF; i <<= 1) p2.insert(i);

    ll a, b, c;
    cin >> a >> b >> c;

    ll p = min({ abs(a), abs(b), abs(c) });
    a /= p, b /= p, c /= p;
    if (a < 0) {
        a = -a, b = -b, c = -c;
    }

    if (a != 1 || b * b - 4 * a * c <= 0) cout << "둘다틀렸근";
    else {
        ll d = -b / a, e = c / a, f = b * b - 4 * a * c;
		if (p2.find(e) != p2.end()) {
			ll x = 2, y = e / 2;
			while (y > 1) {
				if (x + y == d) {
					cout << "이수근";
					return 0;
				}
				x *= 2, y /= 2;
			}
		}

        int is2 = 0;
        for (ll i = 0; i <= 10000; i++)
            if (i * i == f) is2 = 1;

        if (is2) cout << "정수근";
        else cout << "둘다틀렸근";
    }

	return 0;
}