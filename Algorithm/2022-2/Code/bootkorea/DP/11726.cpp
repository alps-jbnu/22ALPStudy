#include <iostream>
using namespace std;

int main(void) {
	int d[1001] = { 0 };
	int n, result;
	cin >> n;

	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}
	cout << d[n] << endl;

	return 0;
}