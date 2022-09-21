#include <bits/stdc++.h>
using namespace std;

string s[5];
bool vis[25];
int cnt = 0,scnt=0;
int ans = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


bool four() {
	int cn = 0;
	for (int i = 0; i < 25; i++) {
		if (vis[i]) {
			int x = i / 5;
			int y = i % 5;
			if (s[x][y] == 'S')	cn++;
		}
	}
	if (cn >= 4)	return true;
	return false;
}

bool bfs() {
	queue<pair<int, int>> q;
	bool check[5][5] = { false };
	bool qcheck[5][5] = { false };
	bool ans_check = false;

	int Tmp = 0;
	for (int i = 0; i < 25; i++) {
		if (vis[i]) {
			int x = i / 5;
			int y = i % 5;
			check[x][y] = 1;
			if (Tmp == 0) {
				q.push({ x,y });
				qcheck[x][y] = 1;
				++Tmp;
			}
		}
	}
	int cnt = 1;
	while (!q.empty()) {

		auto cur = q.front();
		q.pop();

		if (cnt == 7) {
			ans_check = 1;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || y < 0 || x >= 5 || y >= 5)	continue;
			if (check[x][y] && !qcheck[x][y]) {
				qcheck[x][y] = 1;
				q.push({ x,y });
				++cnt;
			}
		}
	}
	if (ans_check)	return true;
	return false;
}
void func(int cur, int num) {
	if (num == 7) {
		if (four()) {
			if (bfs())	++ans;
		}
		return;
	}

	for (int i = cur; i < 25; i++) {
		if (vis[i])	continue;
		vis[i] = 1;
		func(i, num + 1);
		vis[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		cin >> s[i];
	}
	func(0, 0);
	cout << ans;
	
 }