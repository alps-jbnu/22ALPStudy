#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string city[30];
int houseNum[100000];
bool vis[30][30];
int num;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> city[i];

	// 시작점이 안주어졌으므로 이중for문 이용해 찾는다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] || city[i][j] == '0') continue;

			vis[i][j] = true;
			num++; // 단지수 == 시작점 갯수
			queue<pair<int, int>> q;
			q.push({ i, j });
			while (!q.empty()) {
				houseNum[num]++;
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || city[nx][ny] == '0') continue;

					q.push({ nx, ny });
					vis[nx][ny] = true;
				}
			}
		}
	}

	sort(houseNum+1, houseNum + num + 1); // 오름차순으로 정렬
	cout << num << "\n";
	for (int i = 1; i <= num; i++) {
		cout << houseNum[i]<< "\n";
	}
	return 0;
}