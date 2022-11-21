#include <iostream>
#include <algorithm>

#define MAX (201)
#define INF (987654321)

using namespace std;

int N, M;

int graph[MAX][MAX], answer[MAX][MAX];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int from, to, dis;
		cin >> from >> to>>dis;
		graph[from][to] = dis;
		graph[to][from] = dis;
		answer[from][to] = to;
		answer[to][from] = from;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
					answer[i][j] = answer[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N;j++) {
			if (answer[i][j] == 0)
				cout << "- ";
			else
			cout << answer[i][j]<< ' ' ;
		}
		cout << '\n';
	}

	return 0;
}
