#include <iostream>
#include <queue>
#include <vector>
#include <stack>

bool vis[101];
int count;
std::vector<int> V[101];
std::vector<int>::iterator it;
std::stack<int> S;

void dfs() {
	S.push(1);
	while (!S.empty()) {
		int tos = S.top();
		S.pop();
		if (vis[tos]) continue;
		vis[tos] = true;
		count++;
		for (it = V[tos].begin(); it != V[tos].end(); it++) {
			if (vis[*it] == true) continue;
			S.push(*it);
		}
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int u, v, u1, u2;
	std::cin >> u >> v;
	for (int i = 0; i < v; i++) {
		std::cin >> u1 >> u2;
		V[u1].push_back(u2);
		V[u2].push_back(u1);
	}
	dfs();
	std::cout << count << std::endl;
	return 0;
}