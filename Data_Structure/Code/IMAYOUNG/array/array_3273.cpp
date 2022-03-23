#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int a[100000];
	int x;
	int cnt;
	int b[2000000];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> x;

	for (int j = 0; j < n; j++) {
		if (x - a[j] > 0 && b[x - a[j]]){
			cnt++;
		}
		b[a[j]] = true;
	}
	cout << cnt;
}