#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string color[105];
bool visB[105][105];
bool visR[105][105];
bool visG[105][105];
bool visRG[105][105];

int count_B, count_R, count_G, count_RG;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> color[i];

	// Blue
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visB[i][j] || color[i][j] != 'B') continue;

			queue<pair<int, int>> q;
			q.push({ i, j });
			visB[i][j] = true;
			count_B++;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visB[nx][ny] || color[nx][ny] != 'B') continue;

					q.push({ nx, ny });
					visB[nx][ny] = true;
				}
			}
		}
	}

	// Red
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visR[i][j] || color[i][j] != 'R') continue;

			queue<pair<int, int>> q;
			q.push({ i, j });
			visR[i][j] = true;
			count_R++;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visR[nx][ny] || color[nx][ny] != 'R') continue;

					q.push({ nx, ny });
					visR[nx][ny] = true;
				}
			}
		}
	}

	// Green
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visG[i][j] || color[i][j] != 'G') continue;

			queue<pair<int, int>> q;
			q.push({ i, j });
			visG[i][j] = true;
			count_G++;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visG[nx][ny] || color[nx][ny] != 'G') continue;

					q.push({ nx, ny });
					visG[nx][ny] = true;
				}
			}
		}
	}

	// R+G
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visRG[i][j] || color[i][j] == 'B') continue;

			queue<pair<int, int>> q;
			q.push({ i, j });
			visRG[i][j] = true;
			count_RG++;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visRG[nx][ny] || color[nx][ny] == 'B') continue;

					q.push({ nx, ny });
					visRG[nx][ny] = true;
				}
			}
		}
	}
	
	cout << count_B + count_G + count_R << " " << count_B + count_RG;
	
		
	
	return 0;
}
