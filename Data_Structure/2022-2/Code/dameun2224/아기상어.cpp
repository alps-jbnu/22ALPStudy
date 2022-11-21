#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>


using namespace std;

int board[22][22];
int check[22][22];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int second = 0;	// 최종 결과값 
int babysize = 2;	// 아기상어 크기 
int N, x, y;
int eatfish = 0;	// 아기상어가 먹은 물고기 수 


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {		// 입력받기 
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				x = i;	// 아기상어 좌표 기록 
				y = j;
			}
		}
	}

	while (1) {
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				check[i][j] = -1;		// check 초기화 
				
		check[x][y] = 0;	// 시작위치의 거리 0 
		board[x][y] = 0;	// 아기상어가 있는 곳을 9에서 0으로 변경 
		
		queue<pair<int, int>> q;	// 아기 상어의 시작 위치를 넣어줄 큐 
		vector<pair<int, int>> fish;	// 아기 상어가 먹을 수 있는 물고기의 좌표를 넣어줄 벡터 
		
		if (eatfish >= babysize) {	// 아기 상어의 크기 증가 
			eatfish -= babysize;	// 자기 크기보다 많이 먹었을 경우 증가 
			babysize++;
		}
		
		q.push({ x,y });
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;	// 범위 밖이라면 
				if (check[nx][ny] != -1) continue;	// 들린 적 있다면 
				if (board[nx][ny] > babysize) continue;	// 물고기가 아기 상어의 크기보다 크다면 

				else if (board[nx][ny] == babysize || board[nx][ny] == 0) {	// 크기가 같은 물고기를 만났거나 
					check[nx][ny] = check[cur.first][cur.second] + 1;		// 아무것도 없는 곳인 경우 
					q.push({ nx,ny });
				}
				else if (board[nx][ny] < babysize && board[nx][ny] >= 1) {	// 먹을 수 있는 물고기 
					check[nx][ny] = check[cur.first][cur.second] + 1;
					fish.push_back({ nx,ny });	// 벡터에 물고기 좌표 넣어주기 
					q.push({ nx,ny });
				}
			}
		}
		
		if (fish.size() == 0) {	// 먹을 수 있는 물고기가 없을 때 
			cout << second << "\n";
			return 0;
		}
		else if (fish.size() == 1) {	// 하나 먹을 수 있는 경우 
			x = fish[0].first;
			y = fish[0].second;
			board[x][y] = 0;
			eatfish++;
			second += check[x][y];	// 시간을 더해줌 
		}
		else {
			int mindist = 1e5;	// 1e5 = 100000
			for (auto& x : fish) {	// 거리가 가장 가까운 물고기 
				mindist = min(mindist, check[x.first][x.second]);
			}
			int mincnt = 0;	// 거리가 같은 가까운 물고기 세기 
			vector<pair<int, int>> minfish;	// 거리가 같은 물고기를 넣을 벡터 
			for (auto& x : fish) {
				if (mindist == check[x.first][x.second]) {	// 거리가 같으면 벡터에 넣어줌 
					minfish.push_back({ x.first,x.second });
				}
			}
			if (minfish.size() == 1) {
				x = minfish[0].first;
				y = minfish[0].second;
				board[x][y] = 0;
				second += check[x][y];
				eatfish++;
			}
			else {
				sort(minfish.begin(), minfish.end());	// 정렬! 왼쪽에 있는 애를 먹어야하므로 
				x = minfish[0].first;
				y = minfish[0].second;
				second += check[x][y];
				board[x][y] = 0;
				eatfish++;
			}
		}
	}
}