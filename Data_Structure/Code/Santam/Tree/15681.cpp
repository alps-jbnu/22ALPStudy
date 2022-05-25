#include <iostream>
#include <stack>
#include <cstring>
#include <vector>

using namespace std;

int p[100001] = { 0 };
int vis[100001] = { 0 };
vector<int> tree[100001];


void Child_Sum(int n)
{
	vis[n] = 1;
	for (int i = 0;i < tree[n].size();i++)
	{
		if (tree[n][i] == p[n]) continue; //자식의 노드가 부모의 노드일때는 패스
		Child_Sum(tree[n][i]); // 자식 노드의 자식들의 합을 알아내기 위한 재귀
		vis[n] += vis[tree[n][i]]; // 현재 노드에 자식이 보유한 자식들의 합(본인도 포함)을 저장
	}
}

void Dfs(int r)
{
	stack<int> s;
	s.push(r);
	while (!s.empty())
	{
		int cur = s.top(); s.pop();
		for (int i : tree[cur])
		{
			if (p[cur] == i) continue;
			p[i] = cur;
			s.push(i);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, r, q;
	cin >> n >> r >> q;
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	Dfs(r);
	Child_Sum(r);
	for (int i = 0;i < q;i++)
	{
		int t;
		cin >> t;
		cout<<vis[t]<<"\n";
	}

	return 0;
}

/*
각 노드의 부모의 흔적을 남기기 위해 dfs를 돌려서 배열 p에 저장한 후, 각 노드가 자식들의 수가 얼만지 알아내기 위해 재귀적으로 child_sum호출하도록 해서 v배열에 자식 수를 저장
1. dfs함수에 dfs방식으로 각 노드의 부모를 저장함
2. child_sum함수에 재귀적으로 한 노드의 자식들을 더할때 그 자식들의 노드 각각에 child_sum함수에 불러내어 자식들의 수가 얼만지 알아내도록 만듬
3. dfs와 child_sum에 순서대로 root값을 넣어 탐색을 시작해서 필요한 각 배열에 저장, 입력되는 쿼리 값에 해당하는 배열에 저장된 데이터를 출력 
*/