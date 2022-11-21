#include <iostream>
#include <queue>
#include <vector>

std::queue<int> Q;
std::vector<int> V[502];
std::vector<int>::iterator it;
int dist[502];
int count;

void bfs() {
	Q.push(1);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		if (dist[cur] != 0) continue;
		for (it = V[cur].begin(); it != V[cur].end(); it++) {
			if (dist[*it] != 0) continue;
			if (dist[cur] <= 1) {
				dist[*it] = dist[cur] + 1;
				count++;
				Q.push(*it);
			}
		}
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m, u1, u2;
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> u1 >> u2;
		V[u1].push_back(u2);
		V[u2].push_back(u1);
	}
	bfs();
	std::cout << count << std::endl;
	return 0;
}