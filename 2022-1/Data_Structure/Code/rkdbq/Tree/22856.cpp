#include <iostream>
using namespace std;

int N, ans{ -1 }, la;
int l[100001], r[100001];
bool endChk;

void lastNode(int cur) {
	la = cur;
	if (r[cur] != -1) lastNode(r[cur]);
}
void inorderLike(int cur) {
	ans++;
	if (l[cur] != -1) {
		inorderLike(l[cur]);
		if (!endChk) ans++;
	}
	if (r[cur] != -1) {
		inorderLike(r[cur]);
		if (!endChk) ans++;
	}
	if (cur == la) endChk = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i{}; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		l[a] = b;
		r[a] = c;
	}
	lastNode(1);
	inorderLike(1);
	cout << ans;
	return 0;
}