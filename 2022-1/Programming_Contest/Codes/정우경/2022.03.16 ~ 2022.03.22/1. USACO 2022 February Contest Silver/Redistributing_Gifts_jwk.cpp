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

int n, a[505][505];
vt<int> adj[505], gifts[505];

void input() {
    cin >> n;
    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) {
            cin >> a[i][j];
        }
    }
}

void graphModeling() {
    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) {
            adj[i].push_back(a[i][j]);
            if (a[i][j] == i) break;
        }
    }
}

int visited[505][505];

void dfs(int st, int v) {
    visited[st][v] = 1;
    EACH(u, adj[v]) {
        if (visited[st][u]) continue;
        dfs(st, u);
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

	input();

    graphModeling();

    FOR(i, 1, n + 1) dfs(i, i);

    FOR(i, 1, n + 1) {
        EACH(j, adj[i]) {
            if (visited[j][i]) {
                cout << j << '\n';
                break;
            }
        }
    }

	return 0;
}
