#include <iostream>
#include <queue>
using namespace std;

const int MAX{ 1000001 };
int F, S, G, U, D;
bool vis[MAX];
int cnt[MAX];
queue<int> Q;
int dx[2];

//void init() {
//	for (int i{}; i < MAX; i++) {
//		cnt[i] = MAX;
//	}
//}
void bfs() {
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i{}; i < 2; i++) {
			int nex = cur + dx[i];
			if (nex < 0 || nex >= F) continue;
			if (vis[nex]) continue;
			cnt[nex] = cnt[cur] + 1;
			Q.push(nex);
			vis[nex] = true;
			//cout << nex << " push\n";
		}
	}
}
void ans() {
	if (vis[G - 1]) cout << cnt[G - 1];
	else cout << "use the stairs";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> F >> S >> G >> U >> D;
	dx[0] = U;
	dx[1] = -D;
	Q.push(S - 1);
	vis[S - 1] = true;
	bfs();
	ans();
	return 0;
}