#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char board[14][8];
bool vis[14][8];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans;	// 결과

int main(void) {
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int> > q;
	while (1) {
		vector<pair<int, int> > boom = {};
		for (int k = 1; k <= 12; k++) {		// vis 초기화
			for (int l = 1; l <= 6; l++) {
				vis[k][l] = false;
			}
		}

		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 6; j++) {
				if (board[i][j] == '.') {
					vis[i][j] = true;
					continue;
				}
				if (vis[i][j]) continue;
				
				q.push({ i,j });
				vis[i][j] = true;
				char color = board[i][j];
				int cnt = 1;
				vector<pair<int, int> > record = {};
				record.push_back({ i,j });

				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 1 || nx > 12 || ny < 1 || ny > 6) continue;
						if (vis[nx][ny]) continue;
						if (board[nx][ny] != color) continue;
						
						record.push_back({ nx, ny });
						q.push({ nx, ny });
						vis[nx][ny] = 1;
						cnt++;
					}
				}

				// boom에 record 추가
				if (cnt >= 4) {
					for (int k = 0; k < record.size(); k++) {
						boom.push_back({ record[k].first, record[k].second });
					}
				}
			}
		}
		// 여기까지 전체 while
		// boom에 저장된 좌표 모두 .으로 바꾼 뒤 뿌요 내리기

		// boom에 저장된 좌표 '.'으로 바꾸기
		if (boom.size() == 0) break;	// 종료조건 : 하나도 터지지 않는 경우
		else {
			ans++;
			for (int k = 0; k < boom.size(); k++) {
				board[boom[k].first][boom[k].second] = '.';
			}
		}

		// 뿌요 내리기
		while(1) {
			int flag = 1;
			for (int i = 11; i >= 1; i--) {
				for (int j = 1; j <= 6; j++) {
					if (board[i][j] != '.') {
						if (board[i + 1][j] == '.') {
							char tmp = board[i][j];
							board[i][j] = '.';
							board[i + 1][j] = tmp;
							flag = 0;
						}
					}
				}
			}
			if (flag) break;
		}
	}
	cout << ans << '\n';

	return 0;
}