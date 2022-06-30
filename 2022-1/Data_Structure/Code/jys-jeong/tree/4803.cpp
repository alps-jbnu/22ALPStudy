#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int main() {
	int n, m;
	int accident = 0;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		vector<int> vec[502];
		bool vis[502] = { false };
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		queue<int> q;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int edge = 0;
			int node = 0;
			if (vis[i] == false) {
				q.push(i);
				++cnt;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();

					if (vis[cur])
						continue;

					++node;
					vis[cur] = true;

					for (int j = 0; j < vec[cur].size(); j++) {
						++edge;
						q.push(vec[cur][j]);
					}
				}
				if (edge / 2 != node - 1) {
					--cnt;
				}
			}

		}
		if (cnt >= 2)
			printf("Case %d: A forest of %d trees.\n", ++accident, cnt);
		else if (cnt == 1)
			printf("Case %d: There is one tree.\n", ++accident);
		else
			printf("Case %d: No trees.\n", ++accident);
	}
		
}