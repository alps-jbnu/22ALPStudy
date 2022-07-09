#include <bits/stdc++.h>
using namespace std;
int cntzero=0;
int cntone=0;
int cntmone=0;
int n = 0;
int arr[2200][2200];

void func(int y, int x, int area) {
	int zero = 0, one = 0, mone = 0;
	for (int i = y; i < y + area; i++) {
		for (int j = x; j < x + area; j++) {
			if (arr[i][j] == 1) one++;
			else if (arr[i][j] == 0) zero++;
			else {
				mone++;
			}
		}
	}
	if (zero == 0 && one == 0) cntmone++;
	else if (zero == 0 && mone == 0) cntone++;
	else if (one == 0 && mone == 0) cntzero++;
	else {
		for (int i = y; i < y + area; i = i + area / 3) {
			for (int j = x; j < x + area; j = j + area / 3) func(i, j, area / 3);
		}
	}
	

	
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	func(0, 0, n);
	cout << cntmone << '\n' << cntzero << '\n' << cntone;
}