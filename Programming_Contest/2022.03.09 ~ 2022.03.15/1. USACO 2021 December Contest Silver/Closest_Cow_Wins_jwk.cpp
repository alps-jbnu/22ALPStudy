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

struct pt {
    int p;
    ll t;
};

bool operator<(const pt& a, const pt& b) {
    return a.p < b.p;
}

int k, m, n, iCnt;
vt<pt> gr;
vt<int> f, a[202020];
ll cow1[202020], cow2[202020];
vt<ll> ans;

void input() {
    cin >> k >> m >> n;
    gr.resize(k);
    EACH(i, gr) cin >> i.p >> i.t;
    f.resize(m);
    EACH(i, f) cin >> i;
}

// a[i] = { gr[j] | f[i - 1] <= gr[j].p <= f[i]}
void interval() {
    FOR(k) {
        while (iCnt < m && f[iCnt] < gr[i].p) iCnt++;
        a[iCnt].push_back(i);
    }
    /*FOR(iCnt + 1) {
        if (i == 0) cout << "(-INF, " << f[i] << "]\n";
        else if (i == iCnt) cout << "[" << f[i - 1] << ", INF)\n";
        else cout << "[" << f[i - 1] << ", " << f[i] << "]\n";
        EACH(j, a[i]) cout << gr[j].p << ' ';
        cout << '\n';
    }*/
}

void makingSum() {
    FOR(iCnt + 1) {
        EACH(j, a[i]) {
            if (i == 0 || i == iCnt) cow1[i] += gr[j].t;
            else cow2[i] += gr[j].t;
        }
    }

    FOR(i, 1, iCnt) {
        int len = f[i] - f[i - 1];
        
        ll res = (sz(a[i]) ? gr[a[i][0]].t : 0);
        
        int r = 0;
        FOR(l, sz(a[i])) {
            while (r < sz(a[i]) - 1 && 2 * (gr[a[i][r + 1]].p - gr[a[i][l]].p) < len) {
                res += gr[a[i][++r]].t;
            }
            cow1[i] = max(cow1[i], res);
            res -= gr[a[i][l]].t;
        }
    }
}

ll cal() {
    ans.push_back(cow1[0]);
    ans.push_back(cow1[iCnt]);
    FOR(i, 1, iCnt) {
        ans.push_back(cow1[i]);
        ans.push_back(cow2[i] - cow1[i]);
    }

    sort(ans.rbegin(), ans.rend());

    ans.resize(n);
    
    ll ret = 0;
    EACH(i, ans) ret += i;

    return ret;
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
    
    sort(all(gr));
    sort(all(f));

    interval();

    makingSum();

    cout << cal();

	return 0;
}
