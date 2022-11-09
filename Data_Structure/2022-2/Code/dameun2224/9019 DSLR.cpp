#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;

int A, B;
deque<int> dq1, dq2;
bool vis[10000];
char dir[4] = { 'D', 'S', 'L', 'R' };

string BFS();

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(vis, false, sizeof(vis));	// memset(* ptr, int value, size_t num)
		cin >> A >> B;
		cout << BFS() << endl;
	}

	return 0;
}

string BFS() {
	queue<pair<int, string>> q;
	q.push(make_pair(A, ""));	// 현재 숫자와 변화 저장
	vis[A] = true;

	while (!q.empty()) {
		int cur = q.front().first;	// 최근 숫자
		string change = q.front().second;	// 변화 내용 (D, S, L, R ..)
		q.pop();

		if (cur == B) return change;

		int nxt;
		for (int i = 0; i < 4; i++) {
			if (dir[i] == 'D') {
				nxt = (cur * 2) % 10000;
			}
			else if (dir[i] == 'S') {
				if (cur == 0) nxt = 9999;
				else nxt = cur - 1;
			}
			else if (dir[i] == 'L') {
				nxt = (cur % 1000) * 10 + cur / 1000;
			}
			else if (dir[i] == 'R') {
				nxt = (cur % 10) * 1000 + (cur / 10);
			}
			if (!vis[nxt]) {
				vis[nxt] = true;
				q.push(make_pair(nxt, change + dir[i]));
			}
		}

	}
}
