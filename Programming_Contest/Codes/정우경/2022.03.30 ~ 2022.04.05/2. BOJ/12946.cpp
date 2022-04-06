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
const int dy[] = { 0, 0, 1, -1, 1, -1 };
const int dx[] = { 1, -1, 0, 0, -1, 1 };

int n, ans;
string a[55];
int visited[55][55];

int dfs(int y, int x, int bit) {
    visited[y][x] = bit;
    int ret = 0;
    FOR(6) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
        if (a[ny][nx] == '-') continue;

        if (visited[ny][nx] == -1) ret |= dfs(ny, nx, !bit);
        else if (visited[ny][nx] == bit) ret = 1;
    }
    return ret;
}

void init() {
    FOR(55) memset(visited[i], -1, sizeof(visited[i]));
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

    cin >> n;
    FOR(n) cin >> a[i];

    FOR(y, n) {
        FOR(x, n) {
            if (y > 0 && x > 0 && a[y - 1][x] != '-' && a[y][x - 1] != '-') {
                if (a[y][x] != '-') ans = max(ans, 3);
                if (a[y - 1][x - 1] != '-') ans = max(ans, 3);
            }

            if (a[y][x] == '-') continue;

            ans = max(ans, 1);

            FOR(i, 6) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
                if (a[ny][nx] == '-') continue;
                ans = max(ans, 2);
            }

            init();

            if (dfs(y, x, 0)) ans = max(ans, 3);
        }
    }

    cout << ans;

	return 0;
}