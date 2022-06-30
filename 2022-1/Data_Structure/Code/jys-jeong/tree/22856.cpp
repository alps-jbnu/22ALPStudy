#include<bits/stdc++.h>
using namespace std;


int lc[100001];
int rc[100001];
int res;
int depth;
int mx = 0;

void tree(int n) {
	
	if (lc[n] != -1) {
		++res;
		tree(lc[n]);
		++res;
	}

	if (rc[n] != -1) {
		++res;
		tree(rc[n]);
		++res;
	}
}
void treeright(int n)
{
	if (rc[n] != -1) {
		++depth;
		treeright(rc[n]);
	}
}


int main() {
	int n;
	cin >> n;
	fill(lc, lc + n, -1);
	fill(rc, rc + n, -1);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		lc[a] = b;
		rc[a] = c;
	}
	tree(1);
	treeright(1);
	cout << res-depth;
}