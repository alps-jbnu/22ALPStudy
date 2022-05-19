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

struct abc {
    ll a, b, c;
};

ll n, ans;
vt<abc> a;
map<pll, ll> mp;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

void input() {
    cin >> n;
    a.resize(n);
    EACH(i, a) {
        cin >> i.a >> i.b >> i.c;
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

    EACH(i, a) {
        if (i.a != 0 && i.b != 0) {
            ll g = gcd(abs(i.a), abs(i.b));
            i.a /= g, i.b /= g;
        }
        else {
            if (i.a != 0) i.a = 1;
            if (i.b != 0) i.b = 1;
        }

        if (i.b < 0) i.a *= -1, i.b *= -1;
    }

    EACH(i, a) {
        auto it = mp.find({ i.a, i.b });
        if (it == mp.end()) mp.insert({ { i.a, i.b }, 1 });
        else it->sc++;
    }

    ll ans = n * (n - 1) / 2;
    EACH(i, mp) {
        ans -= i.sc * (i.sc - 1) / 2;
    }

    cout << ans;

	return 0;
}