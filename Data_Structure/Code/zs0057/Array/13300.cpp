#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int room[2][7] = {};
	int a, b = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		room[a][b]++;
	}
	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j < 2; j++) {
			if (room[j][i] > 0) {
				if (room[j][i] % k == 0) {
					cnt += room[j][i] / k;
				}
				else {
					cnt += room[j][i] / k + 1;
				}
			}
		}
	}
	cout << cnt;

}
