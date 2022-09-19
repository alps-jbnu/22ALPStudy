#include<bits/stdc++.h>
using namespace std;

int updown[2] = { 0, };
int button[1000005];
queue<int> q;

int f, s, g, u, d; // f: 총 층의 수, s: 강호의 위치, g: 스타트링크 있는 곳 위치
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> f >> s >> g >> u >> d;
	
	updown[0] = u; 
	updown[1] = -d; // 위, 아래 이동하는 방향 설정

	fill(&button[0], &button[1000004], -1);
	
	q.push(s); // 시작점 == 강호의 위치
	button[s] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + updown[dir];

			if (nx <= 0 || nx > f) continue;
			if (button[nx] != -1) continue;

			q.push(nx);
			button[nx] = button[cur] + 1;
		}
	}


	if (button[g] == -1) cout << "use the stairs";
	else cout << button[g];
	return 0;
}