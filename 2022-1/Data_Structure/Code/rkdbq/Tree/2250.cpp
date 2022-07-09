#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, level{ 1 }, col;
int L[10001], R[10001], P[10001];
bool vis[10001];
vector<int> lv[10001];
int ans[2];

int root() {
	for (int i{ 1 }; i <= N; i++) if (P[i] == 0) return i;
}
void printAns() {
	for (int i{ 1 }; i <= N; i++) {
		if (lv[i].empty()) continue;
		int x{ lv[i][lv[i].size() - 1] - lv[i][0] + 1 };
		if (ans[1] < x) {
			ans[1] = x;
			ans[0] = i;
		}
	}
	for (int i{}; i < 2; i++) cout << ans[i] << " ";
}

void myOrder(int cur) {
	if (L[cur] == -1 && R[cur] == -1) {
		lv[level].push_back(++col);
		vis[cur] = true;
		return;
	}
	if (L[cur] != -1) { 
		level++;
		myOrder(L[cur]); 
		level--;
	}
	if (!vis[cur]) {
		lv[level].push_back(++col);
		vis[cur] = true;
	}
	if (R[cur] != -1) {
		level++;
		myOrder(R[cur]);
		level--;
	}
	if (!vis[cur]) {
		lv[level].push_back(++col);
		vis[cur] = true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i{}; i < N; i++) {
		int n, l, r;
		cin >> n >> l >> r;
		L[n] = l;
		R[n] = r;
		if (l != -1) P[l] = n;
		if (r != -1) P[r] = n;
	}
	myOrder(root());
	printAns();
}