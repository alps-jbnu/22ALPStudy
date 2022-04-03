#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, K;
pair<int, int> leftDown, rightUp;
int dx[4]{ 0,1,0,-1 };
int dy[4]{ 1,0,-1,0 };
bool gridPaper[101][101];
bool vis[101][101];
queue<pair<int, int>> Q;
int ans[101];
int ansIdx;

void bfs() {
	while (!Q.empty()) {
		pair<int, int> curPos{ Q.front().first, Q.front().second };
		Q.pop();
		for (int i{}; i < 4; i++) {
			int nX{ curPos.first + dx[i] };
			int nY{ curPos.second + dy[i] };
			if (nX < 0 || nY < 0 || nX >= M || nY >= N) continue;
			if (gridPaper[nX][nY])  continue;
			if (vis[nX][nY]) continue;
			vis[nX][nY] = true;
			//cout << nX << ", " << nY << "is visited\n";
			Q.push({ nX, nY });
			ans[ansIdx]++;
			//cout << ansIdx << "th size is " << ans[ansIdx] << "\n";
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> M >> N >> K;
	for (int i{}; i < K; i++) {
		int temp{};
		cin >> leftDown.first >> leftDown.second;
		temp = leftDown.first;
		leftDown.first = M - leftDown.second - 1;
		leftDown.second = temp;
		cin >> rightUp.first >> rightUp.second;
		temp = rightUp.first;
		rightUp.first = M - rightUp.second;
		rightUp.second = temp - 1;
		for (int j{ rightUp.first }; j <= leftDown.first; j++) {
			for (int k{ leftDown.second }; k <= rightUp.second; k++) {
				gridPaper[j][k] = true;
			}
		}
	}
	/*for (int i{}; i < M; i++) {
		for (int j{}; j < N; j++) {
			cout << gridPaper[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i{}; i < M; i++) {
		for (int j{}; j < N; j++) {
			if (vis[i][j]) continue;
			if (gridPaper[i][j]) continue;
			Q.push({ i, j });
			vis[i][j] = true;
			ans[ansIdx]++;
			bfs();
			//cout << ans[ansIdx] << "\n";
			ansIdx++;
		}
	}
	sort(ans, ans + ansIdx);
	cout << ansIdx << "\n";
	for (int i{}; i < ansIdx; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}