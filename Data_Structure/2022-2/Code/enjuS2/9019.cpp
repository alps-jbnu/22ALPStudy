#include<iostream>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;

int a, b;
bool vis[10000];

void bfs() {
	queue<pair<int, string>> q;
	q.push({ a, "" });
	vis[a] = true;

	while (!q.empty()) {
		int curNum = q.front().first;
		string curOp = q.front().second;
		q.pop();

		if (curNum == b) {
			cout << curOp << '\n';
			return;
		}

		int d, s, l, r, temp;

		d = (curNum * 2) % 10000;

		if (!vis[d]) {
			vis[d] = true;
			q.push({ d,curOp + "D" });
		}

		s = curNum - 1;
		if (s < 0) {
			s = 9999;
		}
		if (!vis[s]) {
			vis[s] = true;
			q.push({ s,curOp + "S" });
		}

		l = (curNum % 1000) * 10 + (curNum / 1000);
		if (!vis[l]) {
			vis[l] = true;
			q.push({ l,curOp + "L" });
		}

		r = curNum / 10 + (curNum % 10) * 1000;
		if (!vis[r]) {
			vis[r] = true;
			q.push({ r,curOp + "R" });
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		cin >> a >> b;
		memset(vis, false, sizeof(vis));
		bfs();
	}
}