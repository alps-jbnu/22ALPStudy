#include <iostream>
using namespace std;

void Dfs(int n, int idx, int graph[][101], int visited[]) {
	for (int i = 0; i < n; i++) {
		if (!visited[i] && graph[idx][i]) {
			visited[i] = 1;
			Dfs(n, i, graph, visited);
		}
	}
}

int main() {
	int n;
	cin >> n;
	int graph[101][101] = { 0 };
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> graph[i][j];

	for (int i = 0; i < n; i++) {
		int visited[101] = { 0 };
		Dfs(n, i, graph, visited);
		for (int j = 0; j < n; j++) if (visited[j]) graph[i][j] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << graph[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
