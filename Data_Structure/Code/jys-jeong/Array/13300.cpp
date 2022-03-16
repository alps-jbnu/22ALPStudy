#include<bits/stdc++.h>
using namespace std;


int main() {
	int n, k;
	int stu[2][7] = { 0 };
	int cnt = 0;
	cin >> n>>k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		++stu[a][b];
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 6; j++) {
			if (stu[i][j] % k == 0) {
				int a = stu[i][j] / k;
				cnt += a;
			}
			else {
				int a= stu[i][j] / k;
				cnt += a;
				++cnt;
			}
		}
	}
	cout << cnt;
}