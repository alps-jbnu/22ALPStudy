#include<bits/stdc++.h>
using namespace std;

int setNum[9];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n > 0) {
		if (n % 10 == 9) {
			setNum[6]++;
		}
		else setNum[n % 10]++;
		n /= 10;
	}

	if (setNum[6] % 2 == 0) {
		setNum[6] = setNum[6] / 2;
	}
	else setNum[6] = (setNum[6] / 2)+1;

	int max = 0;
	for (int i = 0; i < 9; i++) {
		if (max <= setNum[i]) {
			max = setNum[i];
		}
	}

	cout << max;
	return 0;
}