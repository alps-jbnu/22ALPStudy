#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 나이트 이동 방향 표현
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int length[303][303] = { 0, };
		fill(&length[0][0], &length[302][303], -1);
		// 2차원 배열에서 fill 함수 사용시 반드시 & 사용해야 한다.

		queue<pair<int, int> > q;
		int l, a, b, c, d;
		cin >> l >> a >> b >> c >> d;

		length[a][b] = 0;
		q.push({ a, b });

		// 목적지가 -1인 경우로 만들면 따로 break문 사용 안해도 된다.
		while (length[c][d] == -1) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if (length[nx][ny] != -1) continue;

				length[nx][ny] = length[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
			}
		}
		cout << length[c][d] << "\n";
	}
	
	return 0;
}