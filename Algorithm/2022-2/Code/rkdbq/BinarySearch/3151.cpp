#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int a[10001];
int st, en, cur;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; i++) cin >> a[i];
	sort(a, a + n);

	for (int i{}; i < n; i++) {
		cur = i;
		st = cur + 1;
		en = n - 1;
		while (st != en) {
			if (a[st] + a[en] + a[cur] == 0) cnt++;
			if (abs(a[cur] + a[st]) > abs(a[cur] + a[en])) st++;
			else en--;
		}
	}
	

	return 0;
}