// 2d prefix sum
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

struct xy {
    int x, y;
};

bool operator<(const xy& a, const xy& b) {
    return a.y < b.y;
}

int n, psum[2505][2505];
vt<xy> a;

void input() {
	cin >> n;
	a.resize(n);
	EACH(i, a) {
        cin >> i.x >> i.y;
    }
}

void cc() {
	vt<int> cx(1, -1), cy(1, -1);
	EACH(i, a) {
        cx.push_back(i.x);
		cy.push_back(i.y);
    }

	sort(all(cx));
	sort(all(cy));
	cx.erase(unique(all(cx)), cx.end());
	cy.erase(unique(all(cy)), cy.end());

	EACH(i, a) {
        i.x = lower_bound(all(cx), i.x) - cx.begin();
		i.y = lower_bound(all(cy), i.y) - cy.begin();
		psum[i.y][i.x]++;
    }
}

void makingPsum() {
	FOR(n + 1) {
		FOR(j, n + 1) {
			if (i > 0) psum[i][j] += psum[i - 1][j];
			if (j > 0) psum[i][j] += psum[i][j - 1];
			if (i > 0 && j > 0) psum[i][j] -= psum[i - 1][j - 1];
		}
	}
}

ll sum(int lx, int rx, int ly, int ry) {
	return psum[ry][rx] - psum[ry][lx - 1] - psum[ly - 1][rx] + psum[ly - 1][lx - 1];
}

ll f() {
	ll ret = n + 1;

    FOR(n) {
		FOR(j, i + 1, n) {
			int l = a[i].x, r = a[j].x;
			if (l > r) swap(l, r);

			ret += sum(1, l, a[i].y, a[j].y) * sum(r, n, a[i].y, a[j].y);
		}
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

	input();

	cc();

    sort(all(a));

	makingPsum();

	cout << f();

	return 0;
}


// segment tree
/*#define _USE_MATH_DEFINES
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

struct Seg {
	int flag;  // array size
	vector<ll> t;

	void build(int N) {
		for (flag = 1; flag < N; flag <<= 1);
		t.resize(2 * flag);
	}
	void clear(int N) {
		for (int i = flag; i < flag + N; i++) t[i] = 0;
		for (int i = flag - 1; i >= 1; i--) t[i] = t[i << 1] + t[i << 1 | 1];
	}
	void modify(int p) {  // set value at position p
		for (t[p += flag - 1] = 1; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
	}
	ll query(int l, int r) {
		return query(l, r, 1, 1, flag);
	}
	ll query(int l, int r, int n, int nl, int nr) {  // sum on interval [l, r]
		if (r < nl || nr < l) return 0;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
	}
}seg;

struct xy {
    int x, y;
};

bool operator<(const xy& a, const xy& b) {
    return a.y < b.y;
}

int n;
vt<xy> a;

void input() {
	cin >> n;
	a.resize(n);
	EACH(i, a) {
        cin >> i.x >> i.y;
    }
}

void cc() {
	vt<int> cx(1, -1), cy(1, -1);
	EACH(i, a) {
        cx.push_back(i.x);
		cy.push_back(i.y);
    }

	sort(all(cx));
	sort(all(cy));
	cx.erase(unique(all(cx)), cx.end());
	cy.erase(unique(all(cy)), cy.end());

	EACH(i, a) {
        i.x = lower_bound(all(cx), i.x) - cx.begin();
		i.y = lower_bound(all(cy), i.y) - cy.begin();
    }
}

ll f() {
	ll ret = n + 1;

	seg.build(n);
    FOR(n) {
		seg.clear(n);
		seg.modify(a[i].x);

		FOR(j, i + 1, n) {
			seg.modify(a[j].x);

			int l = a[i].x, r = a[j].x;
			if (l > r) swap(l, r);

			ret += seg.query(1, l) * seg.query(r, n);
		}
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

	input();

	cc();

    sort(all(a));

	cout << f();

	return 0;
}*/