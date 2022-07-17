#define INT_MAX 2147483647

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int sol[100001];
int st, en;
int ans[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; i++) cin >> sol[i];
	sort(sol, sol + n);

	st = 0;
	en = n - 1;
	ans[0] = INT_MAX;
	while (st != en) {
		if (abs(ans[0]) >= abs(sol[en] + sol[st])) {
			ans[0] = sol[en] + sol[st];
			//ans[1] = sol[st];
			//ans[2] = sol[en];
		}
		if (abs(sol[st]) < abs(sol[en])) en--;
		else st++;
	}
	cout << ans[0] << "\n";

	return 0;
}