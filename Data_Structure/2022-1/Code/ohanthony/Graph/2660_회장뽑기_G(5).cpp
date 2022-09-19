#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

int member[55][55];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			member[i][j] = INF; // 멤버간 거리 INF로 초기화
		}
	}

	while (1) {
		int a, b;
		cin >> a >> b;
		if (a + b == -2) break; // 무한 반복문 종료조건

		member[a][b] = 1;
		member[b][a] = 1; // 서로 아는 사람일 경우 값의 변화를 위해 1로 초기화
	}

	// 플로이드 와샬 알고리즘
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				member[i][j] = min(member[i][j], member[i][k] + member[k][j]);
			}
		}
	}

	int result = 9999;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			temp = max(temp, member[i][j]);
		}
		if (temp < result) {
			v.clear();
			v.push_back(i);
			result = temp;
		}
		else if (temp == result) v.push_back(i);
	}

	sort(v.begin(), v.end());

	cout << result << " " << v.size() << "\n";
	for (auto nxt : v) {
		cout << nxt << " ";
	}

	return 0;
} 
