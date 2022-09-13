#include <bits/stdc++.h>
using namespace std;

int n;
int d[45][2];


int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	d[0][0] = 1;
	d[0][1] = 0;
	d[1][0] = 0;
	d[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		d[i][0] = d[i - 1][0] + d[i - 2][0];
		d[i][1] = d[i - 1][1] + d[i - 2][1];
	}

	while (n--) {
		int t;
		cin >> t;
		cout << d[t][0] << ' ' << d[t][1] << '\n';
	}
	
}