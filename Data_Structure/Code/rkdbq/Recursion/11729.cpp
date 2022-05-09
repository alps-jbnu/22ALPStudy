#include <iostream>
#include <cmath>
using namespace std;

int N;
void printK(int p1, int p2, int n) {
	if (n == 1) {
		cout << p1 << " " << p2 << "\n";
		return;
	}
	printK(p1, 6 - p1 - p2, n - 1);
	cout << p1 << " " << p2 << "\n";
	printK(6 - p1 - p2, p2, n - 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	cout << (long long)pow(2, N) - 1 << "\n";
	printK(1, 3, N);
	return 0;
}