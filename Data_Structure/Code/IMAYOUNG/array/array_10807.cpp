#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[100];
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int v;
	cin >> v;

	for (int i = 0; i < n; i++) {
		if (a[i] == v) {
			cnt++;
		}
		else {
			cout << "0";
		}
	}

	cout << cnt;
}