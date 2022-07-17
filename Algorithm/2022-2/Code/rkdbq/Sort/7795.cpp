#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, T;
int A[20001], B[20001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int k{}; k < T; k++) {
		int cnt{};

		cin >> N >> M;
		for (int i{}; i < N; i++) cin >> A[i];
		for (int i{}; i < M; i++) cin >> B[i];

		sort(A, A + N, greater<>());
		sort(B, B + M);

		for (int i{}; i < N; i++) {
			if (A[i] <= B[0]) break;
			for (int j{}; j < M; j++) {
				//cout << A[i] << " " << B[j] << "\n";
				if (A[i] <= B[j]) break;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}