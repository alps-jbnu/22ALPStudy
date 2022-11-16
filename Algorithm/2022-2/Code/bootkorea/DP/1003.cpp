#include <stdio.h>
using namespace std;

int main() {
	int T, N;
	int size = 42;
	int fib[size];
	fib[0] = 1;
	fib[1] = 0;
	for (int i = 2; i < size; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%d %d\n", fib[N], fib[N + 1]);
	}
}