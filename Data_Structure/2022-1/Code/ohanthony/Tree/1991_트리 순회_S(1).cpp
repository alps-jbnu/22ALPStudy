#include<bits/stdc++.h>
using namespace std;

char lc[26], rc[26];

void preorder(int cur) {
	cout << (char)(cur + 'A');
	if (lc[cur] != 0) preorder(lc[cur] - 'A');
	if (rc[cur] != 0) preorder(rc[cur] - 'A');
}

void inorder(int cur) {
	if (lc[cur] != 0) inorder(lc[cur] - 'A');
	cout << (char)(cur + 'A');
	if (rc[cur] != 0) inorder(rc[cur] - 'A');
}

void postorder(int cur) {
	if (lc[cur] != 0) postorder(lc[cur] - 'A');
	if (rc[cur] != 0) postorder(rc[cur] - 'A');
	cout << (char)(cur + 'A');
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	while (n--) {
		char me, left, right;
		cin >> me >> left >> right;


		if (left != '.') lc[me - 'A'] = left;
		if (right != '.') rc[me - 'A'] = right;
	}

	preorder(0);
	cout << "\n";

	inorder(0);
	cout << "\n";

	postorder(0);

	return 0;
}