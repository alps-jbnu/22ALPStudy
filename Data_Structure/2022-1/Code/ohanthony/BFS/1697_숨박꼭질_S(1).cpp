#include<bits/stdc++.h>
using namespace std;

int timeconsume[100005]; // 걸리는 시간

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(timeconsume, timeconsume + 100005, -1); // BFS 활용하므로 모든 값 -1로 초기화

	int n, k;
	cin >> n >> k;

	timeconsume[n] = 0;
	queue<int> q;
	q.push(n);

	// 수빈이가 k위치까지 도달할때까지 반복
	while (timeconsume[k] == -1) {
		auto cur = q.front();
		q.pop();
		for (auto nxt : { cur + 1, cur - 1, cur * 2 }) {
			if (nxt < 0 || nxt > 100000) continue; // 주어진 범위 벗어나지 않는지 먼저 판단
			if (timeconsume[nxt] > -1) continue;

			timeconsume[nxt] = timeconsume[cur] + 1;
			q.push(nxt);
		}
	}

	cout << timeconsume[k];
	return 0;
}