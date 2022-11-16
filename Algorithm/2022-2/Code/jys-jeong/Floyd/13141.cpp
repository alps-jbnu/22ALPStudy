#include<bits/stdc++.h>
using namespace std;

int n, m;
int floyd[205][205];
int mx[205][205];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n+1; i++) {
		fill(floyd[i], floyd[i] + n + 1, INT_MAX/2);
		fill(mx[i], mx[i] + n + 1, -1);
	}
	for (int i = 1; i <= n; i++) {
		floyd[i][i] = 0;
	}
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		floyd[a][b] = min(c,floyd[a][b]);
		floyd[b][a] = floyd[a][b];
		mx[a][b] = max(mx[a][b], c);
		mx[b][a] = mx[a][b];
		
		
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				floyd[j][k] = min(floyd[j][k], floyd[j][i] + floyd[i][k]);
			}
		}
	}
	double long_time, short_time=9999999.0 ,remain_time=0,a;
	
	for (int i = 1; i <= n; i++) {
		long_time = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				a = mx[j][k];
				double b = floyd[i][k] - floyd[i][j];
				if (mx[j][k] != -1) {
					remain_time = (a - b);
					long_time = max(long_time, remain_time / 2 + floyd[i][k]);
					
				}
				
			}
		}
		short_time = min(short_time, long_time);
	}
	cout << fixed;
	cout.precision(1);
	cout << short_time;
}