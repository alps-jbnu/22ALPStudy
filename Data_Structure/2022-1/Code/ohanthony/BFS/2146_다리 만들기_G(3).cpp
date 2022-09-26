#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int island[103][103];
int bridge[103][103]; // 다리 길이
bool vis[103][103];   // 처음 각 섬을 구별할때 쓰이는 방문여부

int n, distinguish, result = 999999;
/*
- distinguish: 각 섬들을 구별하기 위한 숫자 표시
- result: 다리 최소길이
*/

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> island[i][j];
		}
	}

	// 각 섬들을 구별하기 위한 island값 변형
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] || island[i][j] != 1) continue;

			vis[i][j] = true;
			queue<pair<int, int>> q;
			q.push({ i, j });
			distinguish++;
			island[i][j] = distinguish;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || island[nx][ny] != 1) continue;

					q.push({ nx,  ny });
					vis[nx][ny] = true;
					island[nx][ny] = distinguish; //  각 섬들을 1 ,2, 3 ... 이런식으로 구별
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (island[i][j] < 1) continue;

			// 섬들간의 가장 짧은 다리 판별
			fill(&bridge[0][0], &bridge[102][103], -1); // 어느 위치에서든지 각 섬들간의 다리 길이를 판별하기 위한 초기화
			bridge[i][j] = 0;
			queue<pair<int, int>> q;
			q.push({ i, j });
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (bridge[nx][ny] > 0) continue; 

					q.push({ nx,  ny });
					bridge[nx][ny] = bridge[cur.X][cur.Y] + 1;
					if (island[nx][ny] > island[i][j]) { // 다른 섬에 도달할 경우 코드 종료
						result = min(result, bridge[nx][ny]);
						break;
					}
				}
			}

		}
	}
	
	cout << result - 1;
	return 0;
}
