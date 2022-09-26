#include<bits/stdc++.h>
using namespace std;

vector<int> human[505];
int invite[505];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		human[a].push_back(b);
		human[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	invite[1] = 1;

	int result = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		
		for (auto nxt : human[cur]) {
			if (invite[nxt] || invite[cur] >= 3) continue;
			// 문제 조건에서 자신의 친구와 친구의 친구를 초대하기로 했으니 다음과 같은 조건 설정

			q.push(nxt);
			invite[nxt] = invite[cur]+1;
			result++;
		}
	}

	cout << result;
	return 0;
}
