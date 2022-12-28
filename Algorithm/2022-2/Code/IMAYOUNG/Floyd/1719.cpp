#include <iostream>
using namespace std;

//1719번 택배 
//최단거리를 갱신할 때 각 노드에서 두 노드 사이의 중간노드로 가는 
//최단경로방향의 노드가 무엇인지를 기록

//이 문제는 최단 경로가 아니라 최단 경로 중 최초로 거치는 노드 구하는 문제.
//단방향이 아닌 양방향, 이전에 어떤 노드를 거쳤는지를 기록 
int N, M;
int dist[201][201];
int ans[201][201];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			dist[i][j] = dist[j][i] = 1000000007;
		}
	}

	while (M--) { //플로이드 와샬 알고리즘 로직.. 
		int x, y, d; cin >> x >> y >> d;
		if (d < dist[x][y]) {
			dist[x][y] = dist[y][x] = d;
			ans[x][y] = y, ans[y][x] = x;
		}
	}

	for (int k = 1; k <= N; k++) { //i에서 j를 갈 때 모든 k를 거쳐가는 경우 중에서 
		for (int i = 1; i <= N; i++) { // 최솟값을 그래프에 저장해 최단경로 갱신 
			for (int j = i + 1; j <= N; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[j][i] = dist[i][k] + dist[k][j];
					ans[i][j] = ans[i][k], ans[j][i] = ans[j][k];
				}
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) cout << '-' << ' ';
			else cout << ans[i][j] << ' '; //최초로 거치는 노드를 저장하는 배열 
		}
		cout << '\n';
	}
}