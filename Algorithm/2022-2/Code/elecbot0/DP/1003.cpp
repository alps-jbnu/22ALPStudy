#include <bits/stdc++.h>

using namespace std;

int T;

int zero_print[42];
int one_print[42];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	zero_print[0] = 1; zero_print[1] = 0;
	one_print[0] = 0; one_print[1] = 1;
	for (int i = 2; i <= 40; i++) {
		zero_print[i] = zero_print[i - 1] + zero_print[i - 2];
		one_print[i] = one_print[i - 1] + one_print[i - 2];
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N; cin >> N;
		cout << zero_print[N] << " " << one_print[N] << "\n";
	}
	return 0;
}