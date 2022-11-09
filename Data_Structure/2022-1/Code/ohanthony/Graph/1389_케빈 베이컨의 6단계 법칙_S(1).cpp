#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

int relation[105][105];
int result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue; 
			relation[i][j] = INF; // index의 i == j  제외하고 모든 값을 INF으로 초기화
		}
	}

	while (m--) {
		int a, b;
		cin >> a >> b;

		relation[a][b] = 1;
		relation[b][a] = 1; // 서로 아는 사이 == 양방향
	}

	// Floyd-Warshall, 모든 최단 경로를 구함
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				relation[i][j] = min(relation[i][j], relation[i][k] + relation[k][j]);
			}
		}
	}

	int bacon = 9999; 
	for (int i = 1; i <= n; i++) {
		int kevin = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;     // 마찬가지로 자기 자신인 경우 제외
			kevin += relation[i][j];  // 자기와 아는 친구의 경우 다 더함
		}
		if (bacon > kevin) {          // 최솟값 설정
			bacon = kevin;
			result = i;				  // 최솟값일때의 위치를 저장할 식
		}
	}

	cout << result;					  // 결과 출력
	return 0;
} 