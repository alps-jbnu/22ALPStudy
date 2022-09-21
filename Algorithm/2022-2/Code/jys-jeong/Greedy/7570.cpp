#include <bits/stdc++.h>
using namespace std;

int n,ans;
int student[1000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		student[s] = student[s - 1] + 1;
		ans = max(ans, student[s]);
	}
	cout << n - ans;
}