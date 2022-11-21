#define MX_N 100001
#define TASTE_RANGE 1000001

#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C;
int candyNumberSum[TASTE_RANGE * 4];

void insert(int st, int en, int node, int b, int c) {
	if (st > b || en < b) return;
	candyNumberSum[node] += c;
	if (st == en) return;
	int mid{ (st + en) / 2 };
	insert(st, mid, node * 2, b, c);
	insert(mid + 1, en, node * 2 + 1, b, c);
}

void update(int st, int en, int node, int b) {
	int mid{ (st + en) / 2 };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	return 0;
}