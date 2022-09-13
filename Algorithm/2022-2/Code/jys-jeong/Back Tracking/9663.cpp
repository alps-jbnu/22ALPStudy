#include <bits/stdc++.h>
using namespace std;
int n,cnt;
bool a[40];
bool b[40];
bool c[40];

void fun(int cur) {
	if (cur == n) {
		++cnt;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] || b[i + cur] || c[n - 1 + cur - i])	continue;
		a[i] = 1;
		b[i + cur] = 1;
		c[cur - i + n - 1] = 1;
		fun(cur + 1);
		a[i] = 0;
		b[i + cur] = 0;
		c[cur - i + n - 1] = 0;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	fun(0);
	cout << cnt;
	
}