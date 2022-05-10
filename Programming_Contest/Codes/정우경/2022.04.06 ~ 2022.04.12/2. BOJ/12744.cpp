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

int n, cnt, p2[8];
map<vt<int>, int> mp;
int dist[800][70], visited2[7];

void f(int s, vt<int> a) {
    if (s == n) {
        mp.insert({ a, cnt++ });
        return;
    }

    FOR(i, 1, n + 1) {
        if (visited2[i]) continue;
        
        a.push_back(i);
        visited2[i] = 1;

        f(s + 1, a);
        
        a.pop_back();
        visited2[i] = 0;
    }
}

struct xxx {
    vt<int> a;
    int bit;
};

int bfs(vt<int> a, int bit) {
    queue<xxx> q;
    dist[mp.find(a)->sc][bit] = 0;
    q.push({ a, bit });

    while (sz(q)) {
        vt<int> a = q.front().a;
        int bit = q.front().bit, d = dist[mp.find(a)->sc][bit];
        q.pop();

        if (mp.find(a)->sc == 0 && bit == p2[n] - 1) return d;

        FOR(i, 0, n) {
            int nbit = 0;
            vt<int> b;
            FOR(j, n) {
                if (j <= i) {
                    b.push_back(a[i - j]);
                    if ((1 << (i - j)) & bit);
                    else nbit |= (1 << j);
                }
                else {
                    b.push_back(a[j]);
                    if ((1 << j) & bit) nbit |= (1 << j);
                }
            }

            if (dist[mp.find(b)->sc][nbit] != -1) continue;

            q.push({ b, nbit });
            dist[mp.find(b)->sc][nbit] = d + 1;
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

    p2[0] = 1;
    FOR(i, 1, 8) p2[i] = 2 * p2[i - 1];

    FOR(800) {
        FOR(j, 70) dist[i][j] = -1;
    }

	cin >> n;
    
    vt<int> a;
    f(0, a);
    
    int bit = 0;
    a.resize(n);
    FOR(n) {
        char c;
        cin >> a[i] >> c;
        if (c == '+') bit |= (1 << i);
    }
    
    cout << bfs(a, bit);

	return 0;
}