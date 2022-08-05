#include<bits/stdc++.h>
using namespace std;

int people[1002][1002];
int fire[1002][1002];
char chart[1002][1002];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> jihun;
	queue<pair<int, int>> bul;
	for (int i = 0; i < n; i++) {
		fill(fire[i], fire[i] + m, -1);
		fill(people[i], people[i] + m, -1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chart[i][j];
			if (chart[i][j] == 'F') {
				bul.push({ i,j });
				fire[i][j] = 0;
			}
			if (chart[i][j] == 'J') {
				jihun.push({ i,j });
				people[i][j] = 0;
			}
		}
	}

	while (!bul.empty()) {
		auto dot = bul.front();
		bul.pop();
		for (int i = 0; i < 4; i++) {
			int x = dx[i] + dot.first;
			int y = dy[i] + dot.second;
			if (x < 0 || y < 0 || x >= n || y >= m)	continue;
			if (chart[x][y] == '#'||fire[x][y]>=0)	continue;
			fire[x][y] = fire[dot.first][dot.second] + 1;
			bul.push({ x,y });
		}
	}
	while (!jihun.empty()) {
		auto dot = jihun.front();
		jihun.pop();
		for (int i = 0; i < 4; i++) {
			int x = dot.first + dx[i];
			int y = dot.second + dy[i];
			if (x < 0 || y < 0 || x >= n || y >= m) {
				cout << people[dot.first][dot.second] + 1;
				return 0;
			}
			if (people[x][y] >= 0|| chart[x][y] == '#')	continue;
			if (fire[x][y]!=-1&&fire[x][y]<=people[dot.first][dot.second] + 1 )	continue;
			
			people[x][y] = people[dot.first][dot.second] + 1;
			jihun.push({ x,y });
		}

	}
	cout << "IMPOSSIBLE";
}