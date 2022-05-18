#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m;
vector<int>tree[501];
bool Vcheck[501]; // vertex 체크
bool Echeck[501]; // edge 체크
int Vcnt; // 트리에 연결된 노드 개수
int Ecnt; // 트리에 연결된 간선 개수 X 2
int Tcnt; // 전체 트리 개수

void make_tree()
{
	cin >> n >> m;

	for (int i = 0; i < 501; i++)
	{
		tree[i].clear();
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	memset(Vcheck, false, sizeof(Vcheck));
	memset(Echeck, false, sizeof(Echeck));
	Vcnt = 0;
	Ecnt = 0;
	Tcnt = 0;
}

// 트리 조건 : vectex N개 => edge N-1개
// dfs로 root노드에서부터 연결된 노드 개수 체크 
void vertex_num(int node) 
{
	Vcheck[node] = true;
	Vcnt++;

	for (int i = 0; i < tree[node].size(); i++) {
		int next_node = tree[node][i];
		if (!Vcheck[next_node]) {
			vertex_num(next_node);
		}
	}
}

// dfs로 root노드에서부터 연결된 간선 개수 체크
// 단순히 노드별로 연결된 간선 개수 모두 계산하므로 Ecnt = 실제 간선 X 2
void edge_num(int node)
{
	Echeck[node] = true;
	Ecnt += tree[node].size();

	for (int i = 0; i < tree[node].size(); i++) {
		int next_node = tree[node][i];
		if (!Echeck[next_node]) {
			edge_num(next_node);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int idx = 0;
	while (1)
	{
		make_tree();
		idx++;
		
		if (n == 0 && m == 0)
			break;

		for (int i = 1; i <= n; i++) {
			if (!Vcheck[i]) {

				Vcnt = 0;
				Ecnt = 0;

				vertex_num(i);
				edge_num(i);

				// 트리인지 확인
				if ((Vcnt - 1) == (Ecnt / 2)) {
					Tcnt++;
				}
			}
		}

		if (Tcnt == 0) {
			cout << "Case " << idx << ": No trees.\n";
		}
		else if (Tcnt == 1) {
			cout << "Case " << idx << ": There is one tree.\n";
		}
		else {
			cout << "Case " << idx << ": A forest of " << Tcnt << " trees.\n";
		}
	}
}