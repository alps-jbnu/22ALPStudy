#include <iostream>
using namespace std;
#include<algorithm>

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[10] = { 0 };

	int n;
	cin >> n;

	while (1) {
		arr[n % 10]++;
		if (n / 10 == 0) break;
		n /= 10;
	}

	int num = 0;
	for (int i = 0; i < 10; i++) {
		if (i != 9 && i != 6) {
			num = max(num, arr[i]);
		}
	}
	cout << max(num, (arr[6] + arr[9] + 1 / 2));
}