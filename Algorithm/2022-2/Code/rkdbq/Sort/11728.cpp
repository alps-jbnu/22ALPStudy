#include <iostream>
using namespace std;

int N, M;
int A[1000001], B[1000001];
int ans[2000002];

int aIdx, bIdx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i{}; i < N; i++) {
		cin >> A[i];
	}
	for (int i{}; i < M; i++) {
		cin >> B[i];
	}
	for (int i{}; i < N + M; i++) {
		if (aIdx == N) ans[i] = B[bIdx++];
		else if (bIdx == M) ans[i] = A[aIdx++];
		else if (A[aIdx] < B[bIdx]) ans[i] = A[aIdx++];
		else ans[i] = B[bIdx++];
		cout << ans[i] << " ";
	}
	return 0;
}