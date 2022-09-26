#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1};
int dy[4] = { 1, 0, -1, 0};

int w, h;
string building[1005];

int firetime[1005][1005] = { 0, };
int runtime[1005][1005] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		bool isEscape = false; // 탈출했는지 판단하기 위한 bool 변수 선언
		cin >> w >> h;
		queue<pair<int, int> > fire;
		queue<pair<int, int> > run;

		fill(&firetime[0][0], &firetime[1004][1005], -1);
		fill(&runtime[0][0], &runtime[1004][1005], -1);

		for (int i = 0; i < h; i++) {
			cin >> building[i];
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (building[i][j] == '*') { // 불의 시작점
					fire.push({ i, j });
					firetime[i][j] = 0;
				}
				if (building[i][j] == '@') { // 상근의 시작점
					run.push({ i, j });
					runtime[i][j] = 0;
				}
			}
		}

		// 불에 대한 BFS
		while (!fire.empty()) {
			auto cur = fire.front();
			fire.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (firetime[nx][ny] >= 0 || building[nx][ny] == '#') continue;

				firetime[nx][ny] = firetime[cur.X][cur.Y] + 1;
				fire.push({ nx, ny });
			}
		}
		
		// 상근이에 대한 BFS
		while (!run.empty() && !(isEscape)) {
			auto cur = run.front();
			run.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w ) {
					cout << runtime[cur.X][cur.Y] + 1 << "\n";
					isEscape = true;
					break;
				}
				if (runtime[nx][ny] >= 0 || building[nx][ny] == '#') continue;
				if (firetime[nx][ny] != -1 && firetime[nx][ny] <= runtime[cur.X][cur.Y] + 1) continue;

				runtime[nx][ny] = runtime[cur.X][cur.Y] + 1;
				run.push({ nx, ny });
			}
		}
		if (isEscape == false) cout << "IMPOSSIBLE" << "\n";
	}
	
	return 0;
}