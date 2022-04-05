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

int a[3][4];

void input() {
    FOR(4) cin >> a[0][i];
    FOR(4) cin >> a[1][i];
}

int cal2(int b, int c, int d) {
    int cntb1 = 0, cntb2 = 0, cntc = 0, cntd = 0;
    FOR(i, 4) {
        FOR(j, 4) {
            if (a[b][i] > a[c][j]) cntb1++;
            if (a[b][i] < a[c][j]) cntc++;

            if (a[b][i] > a[d][j]) cntb2++;
            if (a[b][i] < a[d][j]) cntd++;
        }
    }

    if (cntb1 > cntc && cntb2 < cntd) return 1;
    if (cntb1 < cntc && cntb2 > cntd) return 1;
    return 0;
}

int cal() {
    int ret = 1;

    ret &= cal2(0, 1, 2);
    ret &= cal2(1, 0, 2);
    ret &= cal2(2, 0, 1);
    
    return ret;
}

int f(int idx) {
    if (idx == 4) {
        return cal();
    }

    int ret = 0;
    FOR(i, 1, 11) {
        a[2][idx] = i;
        ret |= f(idx + 1);
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

	int tc; cin >> tc;

    FOR(tc) {
        input();

        if (f(0)) cout << "yes\n";
        else cout << "no\n";
    }

	return 0;
}