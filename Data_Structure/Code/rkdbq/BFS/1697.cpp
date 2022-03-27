#include <iostream>
#include <queue>
using namespace std;

const int MAX{ 100001 };

int N, K;
int dx[3]{ 1,-1,N };
int visCnt[MAX];
queue<int> curPos;
void bfs() {
	int X{ N };
	while (X != K) {
		dx[2] = X = curPos.front();
		curPos.pop();
		for (int i{}; i < 3; i++) {
			int nX{ X + dx[i] };
			if (nX < 0 || nX > MAX - 1) continue;
			if (visCnt[nX] <= visCnt[X] + 1) continue; //시간 복잡도 관리
			curPos.push(nX);
			visCnt[nX] = visCnt[X] + 1;
			//cout << nX << " visited, " << visCnt[nX] << " sec\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fill_n(visCnt, MAX, MAX);
	cin >> N >> K;
	curPos.push(N);
	visCnt[N] = 0;
	bfs();
	cout << visCnt[K];
	return 0;
}