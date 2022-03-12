#include <iostream>
using namespace std;

int n, x, ans;
int a[100001];
bool chk[2000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; i++) {
		cin >> a[i];
		chk[a[i]] = true;
	}
	cin >> x;
	for (int i{}; i < n; i++) {
		if (x > a[i] && chk[x - a[i]]) ans++;
	}
	cout << ans / 2;

	return 0;
}