#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

long long N, P{ 2 }, Q{ 2 };
unordered_map<long long, long long> A;

long long dfs(long long n) {
	if (A[n] != 0) return A[n];
	else return dfs(n / P) + dfs(n / Q);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> P >> Q;

	A[0] = 1;
	for (long long i{ 1 }; i <= 1000000; i++) {
		A[i] = A[i / P] + A[i / Q];
	}
	cout << dfs(N) << "\n";

	return 0;
}